#ifndef __IEEE_BIG_ENDIAN
#ifndef __IEEE_LITTLE_ENDIAN

#if defined(__arm__) || defined(__thumb__)
/* ARM always has big-endian words.  Within those words the byte ordering
   appears to be big or little endian.  Newlib doesn't seem to care about
   the byte ordering within words.  */
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __hppa__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __sparc__
#ifdef __LITTLE_ENDIAN_DATA__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#endif

#if defined(__m68k__) || defined(__mc68000__)
#define __IEEE_BIG_ENDIAN
#endif

#if defined (__H8300__) || defined (__H8300H__) || defined (__H8300S__)
#define __IEEE_BIG_ENDIAN
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#endif

#ifdef __H8500__
#define __IEEE_BIG_ENDIAN
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#endif

#ifdef __sh__
#ifdef __LITTLE_ENDIAN__
#define __IEEE_LITTLE_ENDIAN
#else
#define __IEEE_BIG_ENDIAN
#endif
#if defined(__SH3E__) || defined(__SH4_SINGLE_ONLY__)
#define _DOUBLE_IS_32BITS
#endif
#endif

#ifdef _AM29K
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __i386__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __i960__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __M32R__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __TIC80__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __MIPSEL__
#define __IEEE_LITTLE_ENDIAN
#endif
#ifdef __MIPSEB__
#define __IEEE_BIG_ENDIAN
#endif

/* necv70 was __IEEE_LITTLE_ENDIAN. */

#ifdef __W65__
#define __IEEE_LITTLE_ENDIAN
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#endif

#if defined(__Z8001__) || defined(__Z8002__)
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __m88k__
#define __IEEE_BIG_ENDIAN
#endif

#ifdef __mn10300__
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __mn10200__
#define __IEEE_LITTLE_ENDIAN
#define __SMALL_BITFIELDS
#define _DOUBLE_IS_32BITS
#endif

#ifdef __v800
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __v850
#define __IEEE_LITTLE_ENDIAN
#endif

#ifdef __D10V__
#define __IEEE_BIG_ENDIAN
#define _DOUBLE_IS_32BITS
#define __SMALL_BITFIELDS
#endif

#ifdef __PPC__
#if (defined(_BIG_ENDIAN) && _BIG_ENDIAN) || (defined(_AIX) && _AIX)
#define __IEEE_BIG_ENDIAN
#else
#if (defined(_LITTLE_ENDIAN) && _LITTLE_ENDIAN) || (defined(__sun__) && __sun__) || (defined(_WIN32) && _WIN32)
#define __IEEE_LITTLE_ENDIAN
#endif
#endif
#endif

#ifdef __arc__
#ifdef __big_endian__
#define __IEEE_BIG_ENDIAN
#else
#define __IEEE_LITTLE_ENDIAN
#endif
#endif

#ifdef __fr30__
#define __IEEE_BIG_ENDIAN
#endif

#ifndef __IEEE_BIG_ENDIAN
#ifndef __IEEE_LITTLE_ENDIAN
#error Endianess not declared!!
#endif /* not __IEEE_LITTLE_ENDIAN */
#endif /* not __IEEE_BIG_ENDIAN */

#endif /* not __IEEE_LITTLE_ENDIAN */
#endif /* not __IEEE_BIG_ENDIAN */
