#include "tmb/file.hpp"

#include <eetypes.h>
#include <libcdvd.h>
#include <sifdev.h>
#include <sifrpc.h>

extern int cdHasBeenInitialized;

extern struct {
    char* tex_files[MAX_FILES_LOADED];
    s8 num_tex_loaded;
    char* ngp_files[MAX_FILES_LOADED];
    s8 num_ngp_loaded;
    char* res_files[MAX_FILES_LOADED];
    s8 num_res_loaded; // offset 0xB0
    char names[MAX_FILES_LOADED][MAX_NAME_LENGTH]; // offset 0xB1
    u16 max_tex_ids[MAX_FILES_LOADED]; // offset 0x130
    u16 max_tex_addrs[MAX_FILES_LOADED];
    u16 max_res_addrs[MAX_FILES_LOADED];
} fileStatus; // size 0x184 (?)

void fileMakeDirTree();
int fileStringCompare(char* lhs, char* rhs);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileReadf__FPcPv);

INCLUDE_RODATA("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", D_004F20F8);

INCLUDE_RODATA("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", D_004F2108);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileReads__FPcPvUi);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileWritef__FPcPvi);

void fileInitializeCd()
{
    int ready;

    sceSifInitRpc(0);
    sceCdInit(SCECdINIT);
    do {
        ready = sceSifRebootIop("cdrom0:\\IOPRP213.IMG;1");
    } while (!ready);
    do {
        ready = sceSifSyncIop();
    } while (!ready);

    sceSifInitRpc(0);
    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);
    sceFsReset();
    do {
        ready = sceCdDiskReady(0);
    } while (ready != SCECdComplete);
    fileMakeDirTree();
    cdHasBeenInitialized = 1;
    do {
        ready = sceCdDiskReady(0);
    } while (ready != SCECdComplete);
}

s8 getTexFilesLoaded()
{
    return fileStatus.num_tex_loaded;
}

s8 getNgpFilesLoaded()
{
    return fileStatus.num_ngp_loaded;
}

s8 getResFilesLoaded()
{
    return fileStatus.num_res_loaded;
}

char* getNextNgpLoadAddr()
{
    return fileStatus.ngp_files[fileStatus.num_ngp_loaded];
}

char* getNextTexLoadAddr()
{
    return fileStatus.tex_files[fileStatus.num_tex_loaded];
}

char* getNextResLoadAddr()
{
    return fileStatus.res_files[fileStatus.num_res_loaded];
}

char* getNgpAddr(int index)
{
    char* result;

    if (index < fileStatus.num_ngp_loaded) {
        result = fileStatus.ngp_files[index];
    } else {
        result = NULL;
    }
    return result;
}

char* getTexAddr(int index)
{
    char* result;

    if (index < fileStatus.num_tex_loaded) {
        result = fileStatus.tex_files[index];
    } else {
        result = NULL;
    }
    return result;
}

char* getResAddr(int index)
{
    char* result;

    if (index < fileStatus.num_res_loaded) {
        result = fileStatus.res_files[index];
    } else {
        result = NULL;
    }
    return result;
}

char* getGenericName(int index)
{
    char* result;

    if (index < fileStatus.num_ngp_loaded) {
        result = fileStatus.names[index];
    } else {
        result = NULL;
    }
    return result;
}

u16 getMaxTexId(int index)
{
    return fileStatus.max_tex_ids[index];
}

u16 getMaxTexAddr(int index)
{
    return fileStatus.max_tex_addrs[index];
}

u16 getMaxResAddr(int index)
{
    return fileStatus.max_res_addrs[index];
}

void setMaxTexId(int index, u16 max)
{
    fileStatus.max_tex_ids[index] = max;
}

void setMaxTexAddr(int index, u16 max)
{
    fileStatus.max_tex_addrs[index] = max;
}

void setMaxResAddr(int index, u16 max)
{
    fileStatus.max_res_addrs[index] = max;
}

s8 getIdxOfAddr(char* file)
{
    for (int i = 0; i < fileStatus.num_tex_loaded; i++) {
        if (fileStatus.tex_files[i] == file) {
            return i;
        }
    }

    return -1;
}

s8 getIdxOfResAddr(char* file)
{
    for (int i = 0; i < fileStatus.num_res_loaded; i++) {
        if (fileStatus.res_files[i] == file) {
            return i;
        }
    }

    return -1;
}

s8 getIdxOfName(char* name)
{
    for (int i = 0; i < fileStatus.num_ngp_loaded; i++) {
        if (fileStringCompare(name, fileStatus.names[i])) {
            return i;
        }
    }

    return -1;
}

void fileAddNgpFile(char* file, int size)
{
    fileStatus.ngp_files[fileStatus.num_ngp_loaded++] = file;
    fileStatus.ngp_files[fileStatus.num_ngp_loaded]
        = fileStatus.ngp_files[fileStatus.num_ngp_loaded - 1] + size;

    u32 align = (u32)fileStatus.ngp_files[fileStatus.num_ngp_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.ngp_files[fileStatus.num_ngp_loaded] += (s8)(0x80 - align);
        fileStatus.ngp_files[fileStatus.num_ngp_loaded] += 0x80;
    }
}

void fileAddTexFile(char* file, int size)
{
    fileStatus.tex_files[fileStatus.num_tex_loaded++] = file;
    fileStatus.tex_files[fileStatus.num_tex_loaded]
        = fileStatus.tex_files[fileStatus.num_tex_loaded - 1] + size;

    u32 align = (u32)fileStatus.tex_files[fileStatus.num_tex_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.tex_files[fileStatus.num_tex_loaded] += (s8)(0x80 - align);
        fileStatus.tex_files[fileStatus.num_tex_loaded] += 0x70;
    }
}

void fileAddResFile(char* file, int size)
{
    fileStatus.res_files[fileStatus.num_res_loaded++] = file;
    fileStatus.res_files[fileStatus.num_res_loaded]
        = fileStatus.res_files[fileStatus.num_res_loaded - 1] + size;

    u32 align = (u32)fileStatus.res_files[fileStatus.num_res_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.res_files[fileStatus.num_res_loaded] += (s8)(0x80 - align);
        fileStatus.res_files[fileStatus.num_res_loaded] += 0x70;
    }
}

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileAddName__FPc);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileOnlyNgpFile__FPci);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileOnlyTexFile__FPci);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileOnlyResFile__FPci);

void fileInitBeforeDbLoad()
{
    for (int i = 0; i < MAX_FILES_LOADED; i++) {
        fileStatus.max_tex_ids[i] = 0;
        fileStatus.max_tex_addrs[i] = 0;
        fileStatus.max_res_addrs[i] = 0;
    }
}

void filePrintFileStatus()
{
    // Debug function, stubbed out of the NTSC release.
}

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileMakeDirTree__Fv);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fourCharsToInt__Fi);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", twoCharsToShort__Fi);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileCdRead__FllPc);

// clang-format off
INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileCdSearchFile__FP10sceCdlFILEPCc);
// clang-format on

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileHierAddrOfSect__FUi);

// clang-format off
INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", filePrintCdFiles__FP13_cdFileSystemi);
// clang-format on

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileStringCompare__FPcT0);

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileTrimPath__FPc);

void fileOutputTime()
{
    // Debug function, stubbed out of the NTSC release.
}

INCLUDE_ASM("/mnt/brahms/projects/tmb-decomp/asm/nonmatchings/tmb/file", fileGetTimeString__Fv);
