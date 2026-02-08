#ifndef __COMMON_H__
#define __COMMON_H__

#include "include_asm.h"

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Helper macro to insert NOPs into a function.
// This is useful if you are decompiling a very large function
// and are unable to compile due to `GPREL` truncations.
#define PAD_ZEROES(num_bytes) asm volatile("  .zero " #num_bytes)

#endif // __COMMON_H__
