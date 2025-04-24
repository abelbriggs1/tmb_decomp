#ifndef _EETYPES_H_
#define _EETYPES_H_

typedef unsigned char u_char;
typedef short unsigned int u_short;
typedef unsigned int u_int;
typedef long unsigned int u_long;
typedef int long128 __attribute__((mode(TI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#ifndef NULL
#define NULL 0
#endif

#endif // _EETYPES_H_
