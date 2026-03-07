#include "tmb/file.hpp"

#include <stdio.h>

#include <eetypes.h>
#include <libcdvd.h>
#include <sifdev.h>
#include <sifrpc.h>

#define SECTOR_BUFFER_SIZE 0x810
#define FILE_SYSTEM_TOC_SIZE 1024
#define FILE_SYSTEM_TOC_NAME_SIZE 16
#define FILE_SYSTEM_TOC_TYPE_DIR 2
#define HALF_MEG 0x80000
#define BYTES_TO_SECTORS(bytes) (((bytes) + 0x7FFu) / 0x800)

// TODO: Most of the names here are guesses based on debug output.
// Figure out where the original TOC structure came from.
typedef struct _cdFileSystem {
    char tNAME[FILE_SYSTEM_TOC_NAME_SIZE];
    u32 tSEC; // Sector location on disc.
    u16 tTYPE; // Type of this file. Directory == 2.
    u16 tNCHLD; // Number of children.
    u32 tSIZ; // Size, in bytes.

    // Array of pointers to children, if this is a directory.
    // Size seems to be unbounded.
    _cdFileSystem* tCHLD[1];
} CdFileSystem; // size 0x20

// Note: TOC structures are not necessarily `0x20` in size in the case of
// directories. This should not be indexed as an array of `CdFileSystem`.
// Only the first element is guaranteed to be aligned as expected.
CdFileSystem cdFileSystemToc[FILE_SYSTEM_TOC_SIZE] = { 0 };
static u8 cdSectorBuffer[SECTOR_BUFFER_SIZE] = { 0 };
static struct {
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
} fileStatus = { 0 }; // size 0x184 (?)
static char globalTimeString[24] = { 0 };

// sdata
extern int cdHasBeenInitialized; //= 0;
// static char _ROOT[] = "Root\n";
// static char _SPACE[] = "  ";
// static char _DIR[] = " + %s";
// static char _FILENAME[] = "  -%16s";
extern sceCdRMode cdReadMode; //= { 0 };

void fileMakeDirTree();
int fileStringCompare(char* lhs, char* rhs);
s32 fourCharsToInt(int offset);
s16 twoCharsToShort(int offset);
int fileCdRead(long sectors, long lbn, char* buf);
bool fileCdSearchFile(sceCdlFILE* file, const char* file_name);

INCLUDE_ASM("asm/nonmatchings/tmb/file", fileReadf__FPcPv);
// int fileReadf(char* file_name, void* dst)
// {
//     int reads = 0;

//     sceCdlFILE file;
//     file.lsn = 0;
//     file.size = 0;
//     file.name[0] = '\0';
//     file.date[0] = '\0';

//     if (!fileCdSearchFile(&file, file_name)) {
//         printf("Couldn't find the file %s. TOC at %p\n", file_name, cdFileSystemToc);
//         return 0;
//     }
//     sceCdSync(0);

//     bool stop;
//     do {
//         if (sceCdRead(file.lsn, BYTES_TO_SECTORS(file.size), dst, &cdReadMode)) {
//             sceCdSync(0);
//             stop = true;
//             if (sceCdGetError() != SCECdErNO) {
//                 stop = false;
//                 printf("\t\tError #%i\n", sceCdGetError());
//             }
//         } else {
//             reads++;
//             stop = false;
//             if (reads == 1 || reads % 200 == 0) {
//                 printf("*-*=* Cmd Not Issued Properly*=*-*\n");
//             }
//         }
//     } while (!stop);

//     return file.size;
// }

INCLUDE_RODATA("asm/nonmatchings/tmb/file", D_004F20F8);

INCLUDE_RODATA("asm/nonmatchings/tmb/file", D_004F2108);

INCLUDE_ASM("asm/nonmatchings/tmb/file", fileReads__FPcPvUi);
// int fileReads(char* file_name, void* dst, u32 size)
// {
//     u32 f_size;
//     u32 lbn;
//     int reads = 0;

//     sceCdlFILE file;
//     file.lsn = 0;
//     file.size = 0;
//     file.name[0] = '\0';
//     file.date[0] = '\0';

//     if (!fileCdSearchFile(&file, file_name)) {
//         printf("Couldn't find the file %s.\n", file_name);
//         return 0;
//     }

//     // f_size = file.size <= (size + 1) * HALF_MEG ? file.size - size * HALF_MEG : HALF_MEG;
//     f_size = HALF_MEG;
//     if (file.size <= (size + 1) * HALF_MEG) {
//         f_size = file.size - size * HALF_MEG;
//     }

//     // Prototypes indicate there was a loop here that was likely dummied out.
//     do {
//     } while (0);
//     lbn = file.lsn + size * 0x100;

//     sceCdSync(0);

// loop:
//     bool stop;
//     if (sceCdRead(lbn, BYTES_TO_SECTORS(f_size), dst, &cdReadMode)) {
//         sceCdSync(0);
//         stop = true;
//         if (sceCdGetError() != SCECdErNO) {
//             stop = false;
//             printf("\t\tError #%i\n", sceCdGetError());
//         }
//     } else {
//         reads++;
//         stop = false;
//         if (reads == 1 || reads % 200 == 0) {
//             printf("*-*=* Cmd Not Issued Properly*=*-*\n");
//         }
//     }

//     if (!stop)
//         goto loop;

//     return f_size;
// }

int fileWritef(char* file_name, void* buf, int size)
{
    int fd = sceOpen(file_name, SCE_TRUNC | SCE_CREAT | SCE_WRONLY);
    if (fd < 0) {
        return -2;
    }

    sceWrite(fd, buf, size);
    sceClose(fd);
    return 0;
}

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

void fileAddName(char* name)
{
    for (int i = 0; i < MAX_NAME_LENGTH; i++) {
        fileStatus.names[fileStatus.num_ngp_loaded - 1][i] = '\0';
    }

    for (int i = 0; name[i] && i < MAX_NAME_LENGTH - 1; i++) {
        fileStatus.names[fileStatus.num_ngp_loaded - 1][i] = name[i];
    }
}

void fileOnlyNgpFile(char* file, int size)
{
    fileStatus.ngp_files[1] = file + size;
    fileStatus.ngp_files[0] = file;
    fileStatus.num_ngp_loaded = 1;

    u32 align = (u32)fileStatus.ngp_files[fileStatus.num_ngp_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.ngp_files[fileStatus.num_ngp_loaded] += (s8)(0x80 - align);
        fileStatus.ngp_files[fileStatus.num_ngp_loaded] += 0x80;
    }
}

void fileOnlyTexFile(char* file, int size)
{
    fileStatus.tex_files[1] = file + size;
    fileStatus.tex_files[0] = file;
    fileStatus.num_tex_loaded = 1;

    u32 align = (u32)fileStatus.tex_files[fileStatus.num_tex_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.tex_files[fileStatus.num_tex_loaded] += (s8)(0x80 - align);
        fileStatus.tex_files[fileStatus.num_tex_loaded] += 0x70;
    }
}

void fileOnlyResFile(char* file, int size)
{
    fileStatus.res_files[1] = file + size;
    fileStatus.res_files[0] = file;
    fileStatus.num_res_loaded = 1;

    u32 align = (u32)fileStatus.res_files[fileStatus.num_res_loaded] & 0x7F;
    if (align != 0) {
        fileStatus.res_files[fileStatus.num_res_loaded] += (s8)(0x80 - align);
        fileStatus.res_files[fileStatus.num_res_loaded] += 0x70;
    }
}

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

INCLUDE_ASM("asm/nonmatchings/tmb/file", fileMakeDirTree__Fv);

s32 fourCharsToInt(int offset)
{
    return (((u32)cdSectorBuffer[offset]) + ((u32)cdSectorBuffer[offset + 1] << 8)
        + ((u32)cdSectorBuffer[offset + 2] << 16) + ((u32)cdSectorBuffer[offset + 3] << 24));
}

s16 twoCharsToShort(int offset)
{
    return (((u16)cdSectorBuffer[offset]) + ((u16)cdSectorBuffer[offset + 1] << 8));
}

int fileCdRead(long sectors, long lbn, char* buf)
{
    int ret = sceCdRead(lbn, sectors, buf, &cdReadMode);
    sceCdSync(0);
    return ret;
}

// clang-format off
INCLUDE_ASM("asm/nonmatchings/tmb/file", fileCdSearchFile__FP10sceCdlFILEPCc);
// clang-format on

CdFileSystem* fileHierAddrOfSect(u32 sector)
{
    CdFileSystem* root = &cdFileSystemToc[0];
    int num_files = root->tNCHLD;
    int i = 0;

    if (num_files != 0) {
        do {
            CdFileSystem* child = root->tCHLD[i];
            if (child->tSEC == sector) {
                return child;
            }
            i++;
        } while (i < num_files);
    }

    return NULL;
}

// clang-format off
INCLUDE_ASM("asm/nonmatchings/tmb/file", filePrintCdFiles__FP13_cdFileSystemi);
// clang-format on
// void filePrintCdFiles(CdFileSystem* dir, int indent)
// {
//     if (dir == NULL) {
//         dir = &cdFileSystemToc[0];
//     }
//     if (indent == 0) {
//         printf("Root\n");
//     }

//     for (int i = 0; i < dir->tNCHLD; i++) {
//         for (int indents = 0; indents < indent; indents++) {
//             printf("  ");
//         }

//         if (dir->tCHLD[i]->tTYPE == FILE_SYSTEM_TOC_TYPE_DIR) {
//             printf(" + %s", dir->tCHLD[i]->tNAME);
//             printf("<<DIR>>\n");
//             filePrintCdFiles(dir->tCHLD[i], indent + 1);
//         } else {
//             printf("  -%16s", dir->tCHLD[i]->tNAME);
//             printf("\tSEC=%8i\tSIZ=%9i\n", dir->tCHLD[i]->tSEC, ((dir->tCHLD[i]->tSIZ - 1 >> 0xB)
//             + 1) * 0x800);
//         }
//     }
// }

int fileStringCompare(char* lhs, char* rhs)
{
    for (int i = 0; i < FILE_SYSTEM_TOC_NAME_SIZE; i++) {
        if (lhs[i] != rhs[i]) {
            return 0;
        }
        if (lhs[i] == '\0') {
            return 1;
        }
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/tmb/file", fileTrimPath__FPc);

void fileOutputTime()
{
    // Debug function, stubbed out of the NTSC release.
}

char* fileGetTimeString()
{
    sceCdCLOCK rtc;

    if (sceCdReadClock(&rtc) != 0) {
        sprintf(globalTimeString, "%02x:%02x:%02x", rtc.hour, rtc.minute, rtc.second);
    }
    return globalTimeString;
}
