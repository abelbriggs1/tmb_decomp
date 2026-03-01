#ifndef _TMB_FILE_H_
#define _TMB_FILE_H_

#include "common.h"

// Maximum number of each type of file (TEX, NGP, RES) that can be
// loaded at once.
#define MAX_FILES_LOADED 14
#define MAX_NAME_LENGTH 9

void fileInitializeCd();
s8 getTexFilesLoaded();
s8 getNgpFilesLoaded();
s8 getResFilesLoaded();
char* getNextNgpLoadAddr();
char* getNextTexLoadAddr();
char* getNextResLoadAddr();
char* getNgpAddr(int index);
char* getTexAddr(int index);
char* getResAddr(int index);
char* getGenericName(int index);
u16 getMaxTexId(int index);
u16 getMaxTexAddr(int index);
u16 getMaxResAddr(int index);
void setMaxTexId(int index, u16 max);
void setMaxTexAddr(int index, u16 max);
void setMaxResAddr(int index, u16 max);
s8 getIdxOfAddr(char* file); // Specifically, the index of a tex addr.
s8 getIdxOfResAddr(char* file);
s8 getIdxOfName(char* name);
void fileAddNgpFile(char* file, int size);
void fileAddTexFile(char* file, int size);
void fileAddResFile(char* file, int size);

#endif // _TMB_FILE_H_
