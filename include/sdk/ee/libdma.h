/* SCEI CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library  Release 2.0
 */
/* 
 *                      Emotion Engine Library
 *                          Version 0.10
 *                           Shift-JIS
 *
 *      Copyright (C) 1998-1999 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                       libdma - libdma.h
 *                      header file of libdma
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *      0.09            October.07.1998 suzu        initial
 *      0.10            March.25.1999   suzu        use inline function
 *      0.11            May,17,1999     suzu        delete warnings
 */

#ifndef _LIB_DMA_H_
#define _LIB_DMA_H_

#include <eeregs.h>
#include <eetypes.h>

//
// Channels
//
#ifndef SCE_DMA_VIF0
#define SCE_DMA_VIF0		0
#define SCE_DMA_VIF1		1
#define SCE_DMA_GIF		2
#define SCE_DMA_fromIPU		3
#define SCE_DMA_toIPU		4
#define SCE_DMA_SIF0		5
#define SCE_DMA_SIF1		6
#define SCE_DMA_SIF2		7
#define SCE_DMA_fromSPR		8
#define SCE_DMA_toSPR		9
#endif

//
// DMA Tag 
//
typedef struct _sceDmaTag {
	u_short			qwc;		// transfer count
	u_char			mark;		// mark
	u_char			id;		// tag
	struct _sceDmaTag	*next;		// next tag
	u_int			p[2];		// padding
} sceDmaTag __attribute__ ((aligned(16)));

//
// DMA Environmen
//
typedef struct {
	u_char	sts;			// stall source
	u_char	std;			// stall drain
	u_char	mfd;			// MFIFO drain
	u_char	rcycle;			// release cycle
	u_short	express;		// express channel mask
	u_short	notify;			// notify channel mask	
	u_short	sqwc;			// Interleave skip qword count	
	u_short	tqwc;			// Interleave transfer qword count	
	void	*rbadr;			// MFIFO Ring buffer address
	u_int	rbmsk;			// MFIFO Ring buffer mask
} sceDmaEnv;

//
// Channel Attributes
//
typedef struct {
	tD_CHCR	chcr;	u_int	p0[3];	// channel control
	void	*madr;	u_int	p1[3];	// memory address
	u_int	qwc;	u_int	p2[3];	// transfer count
	sceDmaTag	*tadr;	u_int	p3[3];	// tag address
	void	*as0;	u_int	p4[3];	// address stack
	void	*as1;	u_int	p5[3];	// address stack
	u_int	p6[4];			// pad
	u_int	p7[4];			// pad
	void	*sadr;	u_int	p8[3];	// spr address
} sceDmaChan;

// 
// prototypes
//
#ifdef __cplusplus
extern "C" {
#endif
int sceDmaReset(int mode);
int sceDmaDebug(int mode);
int sceDmaPutEnv(sceDmaEnv *env);
sceDmaEnv *sceDmaGetEnv(sceDmaEnv *env);
void *sceDmaPutStallAddr(void *addr);
sceDmaChan *sceDmaGetChan(int id);
void sceDmaSend(sceDmaChan *d, void *tag);
void sceDmaSendN(sceDmaChan *d, void *addr, int size);
void sceDmaSendI(sceDmaChan *d, void *addr, int size);
void sceDmaRecv(sceDmaChan *d);
void sceDmaRecvN(sceDmaChan *d, void *addr, int size);
void sceDmaRecvI(sceDmaChan *d, void *addr, int size);
void sceDmaSendM(void *saddr, int size);
int sceDmaSync(sceDmaChan *d, int mode, int timeout);
int sceDmaWatch(sceDmaChan *d, void *addr, int mode, int timeout);
int sceDmaSyncN(int mode, int timeout);
void sceDmaLastSyncTime(int time[16]);
int sceDmaPause(sceDmaChan *d);
int sceDmaRestart(sceDmaChan *d);
void *sceDmaCallback(int cause, void (*func)());
#ifdef __cplusplus
}
#endif

// select inline function strategy
#ifndef INLINE
#define INLINE	extern inline
#endif

// tag manipulation
//
extern int		sceDmaDebugMode;
extern sceDmaEnv	sceDmaCurrentEnv;	
extern volatile int	sceDmaAlarmTarget;

#define setADR(v,x)	{if ((v)!=(void *)-1) (v)=(sceDmaTag *)(x);}
#define setQWC(v,x)	(v)=(x)
#define setCHCR(v,m,d)	(v).MOD=(m),(v).DIR=(d),(v).STR=1
#define settag(t,i,a,q)	(t)->id=(i),(t)->next=(sceDmaTag *)(a),(t)->qwc=(u_short)(q)

// Tag manipulation
INLINE sceDmaTag *sceDmaGetNextTag(sceDmaTag *tag)
{
	switch (tag->id&0x70) {
	    case 0x30:
	    case 0x40:
		return(tag+1);
	    case 0x10:
		return(tag+1+tag->qwc);
	    case 0x20:
	    case 0x50:
		return(tag->next);
	}
	return(0);
}

INLINE void sceDmaAddExpress(sceDmaTag *tag)
{
	sceDmaTag *ntag;
	if ((ntag = sceDmaGetNextTag(tag)) != 0) {
		tag ->id = (u_char)((tag->id&0xf0)|0x0c);	// PCE: on
		ntag->id = (u_char)((tag->id&0xf0)|0x08);	// PCE: off
	}
}

INLINE void *sceDmaAddRef(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x30,addr,qwc);
	(*tag)++;
	return(addr);
}

INLINE void *sceDmaAddRefe(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x00,addr,qwc);
	(*tag)++;
	return(addr);

}

INLINE void *sceDmaAddRefs(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x40,addr,qwc);
	(*tag)++;
	return(addr);

}

INLINE void *sceDmaAddCont(sceDmaTag **tag, int qwc)
{
	void *ret;
	settag(*tag,0x10,0,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddNext(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x20,addr,qwc);
	ret  = *tag+1;
	*tag = (sceDmaTag *)addr;
	return(ret);
}

INLINE void *sceDmaAddCall(sceDmaTag **tag, int qwc, void *ctag)
{
	void *ret;
	settag(*tag,0x50,ctag,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddRet(sceDmaTag **tag, int qwc)
{
	void *ret;
	settag(*tag,0x60,0,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddEnd(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x70,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddDest(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x10,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddDests(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x00,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddIRef(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x30|0x80,addr,qwc);
	(*tag)++;
	return(addr);
}

INLINE void *sceDmaAddIRefe(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x00|0x80,addr,qwc);
	(*tag)++;
	return(addr);

}

INLINE void *sceDmaAddIRefs(sceDmaTag **tag, int qwc, void *addr)
{
	settag(*tag,0x40|0x80,addr,qwc);
	(*tag)++;
	return(addr);

}

INLINE void *sceDmaAddICont(sceDmaTag **tag, int qwc)
{
	void *ret;
	settag(*tag,0x10|0x80,0,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddINext(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x20|0x80,addr,qwc);
	ret  = *tag+1;
	*tag = (sceDmaTag *)addr;
	return(ret);
}

INLINE void *sceDmaAddICall(sceDmaTag **tag, int qwc, void *ctag)
{
	void *ret;
	settag(*tag,0x50|0x80,ctag,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddIRet(sceDmaTag **tag, int qwc)
{
	void *ret;
	settag(*tag,0x60|0x80,0,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddIEnd(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x70|0x80,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddIDest(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x10|0x80,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

INLINE void *sceDmaAddIDests(sceDmaTag **tag, int qwc, void *addr)
{
	void *ret;
	settag(*tag,0x00|0x80,addr,qwc);
	ret = *tag+1;
	(*tag) += qwc+1;
	return(ret);
}

#undef setADR
#undef setQWC
#undef setCHCR
#undef settag
#undef INLINE
#endif

