/* SCEI CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library  Release 2.0
 */
/*
 *                      Emotion Engine Library
 *                          Version 0.1.0
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-1999 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                         sifdev.h
 *                         develop library
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       0.1.0         
 */

#ifndef _SIFDEV_H_DEFS
#define _SIFDEV_H_DEFS

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

/* Flag for sceOpen() */
#define SCE_RDONLY      0x0001
#define SCE_WRONLY      0x0002
#define SCE_RDWR        0x0003
#define SCE_NBLOCK      0x0010  /* Non-Blocking I/O */
#define SCE_APPEND      0x0100  /* append (writes guaranteed at the end) */
#define SCE_CREAT       0x0200  /* open with file create */
#define SCE_TRUNC       0x0400  /* open with truncation */
#define SCE_NOBUF       0x4000  /* no device buffer and console interrupt */
#define SCE_NOWAIT      0x8000  /* asyncronous i/o */

/* SCE local usage */
#define SCE_USING       0x10000000  /* io descript usage bit */
#define SCE_NOWBDC      0x20000000  /* not write back d cashe */

/* Seek Code */
#define SCE_SEEK_SET	0
#define SCE_SEEK_CUR	1
#define SCE_SEEK_END	2

/* Ioctl Code */
#define SCE_FS_EXECUTING	0x1

#define SCE_PAD_ADDRESS		0x1

/* Error codes */
#define	SCE_ENXIO	6	/* No such device or address */
#define	SCE_EBADF	9	/* Bad file number */
#define	SCE_ENODEV	19	/* No such device */
#define	SCE_EINVAL	22	/* Invalid argument */
#define	SCE_EMFILE	24	/* Too many open files */

#define	SCE_EBINDMISS		0x10000
#define	SCE_ECALLMISS		0x10001
#define	SCE_ETYPEMISS		0x10002
#define	SCE_ELOADMISS		0x10003
#define	SCE_EVERSIONMISS	0x10004

extern int  sceOpen(char *filename, int flag);
extern int  sceClose(int fd);
extern int  sceRead(int fd, void *buf, int nbyte);
extern int  sceWrite(int fd, void *buf, int nbyte);
extern int  sceLseek(int fd, int offset, int whence);
extern int  sceIoctl(int fd, int req, void *);
extern int  sceFsReset(void);

#define SCE_STM_R	0x0001
#define SCE_STM_W	0x0002
#define SCE_STM_X	0x0004
#define SCE_STM_C	0x0008
#define SCE_STM_F	0x0010
#define SCE_STM_D	0x0020

extern int sceSifInitIopHeap(void);
extern void *sceSifAllocIopHeap(int);
extern int sceSifFreeIopHeap(void *);
extern int sceSifLoadIopHeap(char *, void *);

/* ee load file routine */
typedef struct {
	unsigned int epc;
	unsigned int gp;
	unsigned int sp;
	unsigned int dummy;  
} sceExecData;

#define SCE_SIF_TYPECHAR	0
#define SCE_SIF_TYPESHORT	1
#define SCE_SIF_TYPEINT		2

extern int sceSifLoadModule(char *filename, int args, char *argp);
extern int sceSifLoadElf(char *name, sceExecData *data);
extern int sceSifLoadElfPart(char *name, char *secname, sceExecData *data);
extern int sceSifLoadFileReset(void);

extern int sceSifRebootIop(char *img);
extern int sceSifSyncIop(void);

#define IOP_IMAGE_FILE "IOPRP20.IMG"
#define IOP_IMAGE_file "ioprp20.img"

/* extern int errno; */


#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _SIFDEV_H_DEFS */

/* End of File */
