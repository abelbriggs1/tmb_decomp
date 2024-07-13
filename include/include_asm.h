#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

// #define STRINGIFY_(x) #x
// #define STRINGIFY(x) STRINGIFY_(x)

#ifndef PERMUTER

#ifndef INCLUDE_ASM

#define INCLUDE_ASM(FOLDER, NAME)                                                                  \
    __asm__(".text\n"                                                                              \
            "\t.align\t3\n"                                                                        \
            "\t.set noreorder\n"                                                                   \
            "\t.set noat\n"                                                                        \
            ".include \"" FOLDER "/" #NAME ".s\"\n"                                                \
            "\t.set reorder\n"                                                                     \
            "\t.set at\n")
#define INCLUDE_RODATA(FOLDER, NAME)                                                               \
    __asm__(".section .rodata\n"                                                                   \
            "\t.include \"" FOLDER "/" #NAME ".s\"\n"                                              \
            ".section .text")
#endif // INCLUDE_ASM
__asm__(".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif // PERMUTER

#endif // INCLUDE_ASM_H
