# Contributing

## Developer Setup

This repository currently assumes that the user is running a Debian/Ubuntu-based
Linux distribution. If you are a Windows user, you can use
[Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/about)
with Ubuntu.

To set up the repository, simply install the required packages as detailed in
[Requirements](README.md#requirements).

## Repository Layout

- `asm/`
  - Contains raw MIPSEL R5900 Emotion Engine assembly files, split and disassembled
    from the original binary by the `splat` tool.
- `assets/`
  - Contains raw binary blobs split from the original binary by `splat`.
  - TMB doesn't include any real game assets in the binary. The binary blobs in
    here are mostly debug info/ELF sections from the original binary that are
    linked directly into the new binary.
- `build/`
  - Contains the build artifacts / objects.
- `config/`
  - Contains the `splat` configuration file, symbol lists, and generated linker script.
- `disks/`
  - Contains the original `SCUS_971.01` binary.
- `include/`
  - Contains header files for the decompilation.
- `src/`
  - Contains C/C++ source files for the decompilation.
- `tools/`
  - Contains the compiler and build scripts for this repository.

## Resources

It's highly recommended to join some or all of the following Discord groups dedicated
to decompilation if you'd like help or resources on decompilation. Many people here are
experienced with reverse engineering and can help with a lot of issues.

[PS1/PS2 Decompilation](https://discord.gg/VwCPdfbxgm)

[`decomp.me`](https://discord.gg/fGjbfPeGTX)

### `decomp.me`

[decomp.me](https://decomp.me) is an online tool that allows you to collaborate with
others on decompiling code through a web interface. It's very helpful for getting a
visual representation of your code.

This repository doesn't have any integration with `decomp.me` currently, so setting
up scratches for TMB code can be annoying. Here's a very brief guide to creating a
scratch for TMB:

1. Go to https://decomp.me/new.
2. Under `Platform`, select `Playstation 2 - MIPS (little-endian)`.
3. Under `Compiler`, select `EE GCC 2.9 build 991111` as the compiler with `Custom` preset.
4. Under `Target assembly`, copy-paste the contents of the function you are matching
   from its corresponding file in `asm/nonmatchings/`.
5. Under `Context`, add all typedefs from `include/common.h`.
6. Click `Create scratch`.
7. On the new page, in the `Options` tab of the left window, enter
   `-O2 -G8 -x c++ -fno-exceptions` for the compiler flags.
8. Decompile the code to your heart's content!

## General Workflow

The following is a description of the general workflow a developer will use when
decompiling a **translation unit (TU)**.

This workflow assumes a basic grasp of C and C++ programming. You'll want to
familiarize yourself with the language a bit if you haven't already.

### 1. Split / Migrate Code

In the `splat` config file, `config/US/SCUS_971.01.yaml`, we need to find a translation
unit we want to decompile.

Let's say we want to decompile `tmb/font.cpp`. Since this file's code hasn't been decompiled
yet, it should have a subsegment type of `asm`:

```yaml
  - name: main
    type: code
    start: 0x0
    vram: 0x00100000
    bss_size: 0x255E1C
    align: 4
    subsegments:
      # ------------------------------------------------
      # .text segment (C/C++ code)
      # ------------------------------------------------
      - [0x0000, asm, gcc/_crt0]
      - [0x00C0, asm, tmb/ai]

      # ...

      - [0xC3E48, asm, tmb/font]

      # ...
```

To decompile this as C++, we need to change the subsegment type to `cpp`:

```yaml
      - [0xC3E48, cpp, tmb/font]
```

Now that we've changed the `splat` config, we need to rerun `splat` and regenerate
our Ninja build script. This can be done with `./configure.py generate` in the root
of the repository.

After running `./configure.py generate`, we should have a new file in the `src/`
directory, `src/tmb/font.cpp`:

```cpp
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontInit__F10_vramAddrs);

INCLUDE_ASM("asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

// ...
```

`splat` generates this new C++ file for us. Currently, it's using a bunch of preprocessor
macros to directly include MIPS R5900 assembly code into the C++ file.

If we run `ninja` to build the repository, the binary should still match at this point.

```
[4/5] CHECK       /workspace/build/SCUS_971.01
/workspace/build/SCUS_971.01: OK
```

#### Finding `.rodata`

Unfortunately, you may run into TUs which don't compile after migration to `cpp`.
This is likely because one or more functions in the TU have a `switch()` statement.

GCC compiles `switch()` statements into a [jump table](https://en.wikipedia.org/wiki/Branch_table).
The jump table maps each `case` to the address to branch to. In TMB's case, the
jump tables are always stored in the TU's `.rodata` section. In order to decompile
the code, you'll need to split and decompile `.rodata` first.

This is thankfully fairly easy. Check the [Split/Disassemble Data](#3-splitdisassemble-data)
and [Decompiling Data](#4-decompile-data) sections for how to do this.

### 2. Decompile Code

Now that we have a C++ file that's being included in the build, we need to replace
the included assembly code with C++ code.

**NOTE**: Unfortunately, we don't have a decompiler which supports C++ currently.
You'll want to analyze the binary in Ghidra using the `ghidra-emotionengine-reloaded`
extension to get a decompiler view.

Let's try decompiling a `font.cpp` function. We'll decompile `fontSetCharWidth__Fii` for this
example.

We can find the assembly of the function inside `asm/nonmatchings/tmb/font/fontSetCharWidth_Fii.s`:
```asm
.align 3
glabel fontSetCharWidth__Fii
/* C5380 001C4380 5000023C */  lui        $2, %hi(fontInfo)
/* C5384 001C4384 40210400 */  sll        $4, $4, 5
/* C5388 001C4388 40454224 */  addiu      $2, $2, %lo(fontInfo)
/* C538C 001C438C 21208200 */  addu       $4, $4, $2
/* C5390 001C4390 0800E003 */  jr         $31
/* C5394 001C4394 040085A4 */   sh        $5, 0x4($4)
.size fontSetCharWidth__Fii, . - fontSetCharWidth__Fii
```

A decompiler like Ghidra or M2C will give us a more sane C equivalent:

```c
fontInfo[param_1].field2_0x4 = (short)param_2;
```

We can see thanks to the C++ symbol name (`fontSetCharWidth__Fii`) that this function
accepts two `int`s as arguments, confirming our suspicions. Our decompiled function
ultimately looks like this:

```cpp
void fontSetCharWidth(int param_1, int param_2)
{
    fontInfo[param_1].field2_0x4 = param_2;
}
```

However, there's a problem - the compiler has no idea what `fontInfo`'s layout
actually looks like. It will just throw an error if we try to compile now. To
satisfy the compiler, we need to do two things:

1. Create a `struct` for `fontInfo` so the compiler knows the variable's layout/size.
2. Declare an `extern` symbol for `fontInfo` so the compiler knows it exists.

```cpp
typedef struct {
    u8 unk[0x4];
    u16 field2_0x4;
    u8 unk2[0x1A];
} _fontInfo;

extern _fontInfo fontInfo[2];
```

If we compile with `ninja` again, we have a successful build!

```
[288/289] CHECK       /workspace/build/SCUS_971.01
/workspace/build/SCUS_971.01: OK
```

To summarize the general process, for each function in the file:

1. Comment out the `INCLUDE_ASM` macro for the function.
2. Declare any necessary structures/extern symbols for the function.
3. Define and implement the C/C++ function.
4. Compile and ensure the final binary still matches.

#### Handling Variables

We saw above that `fontSetCharWidth()` needed to reference a module-level variable `fontInfo`, which required the use of `extern`. How do we handle
variables in general? What does `extern` mean? Where is `fontInfo` actually
located?

To understand this, you'll need to understand the difference between
"declaring" a variable and "defining" it.
- A **declared** variable _exists somewhere_.
  - We know its type, but we don't know _where_ it is stored or what initial
    value it might have.
  - This is what `extern _fontInfo fontInfo[2];` accomplishes; it tells GCC
    that `fontInfo` exists so we can reference it in our C++ code.
- A **defined** variable exists _here_.
  - This is what we get if we remove the `extern` qualifier:
    `_fontInfo fontInfo[2];`.
  - GCC now thinks the variable exists in this translation unit,
    `tmb/font.cpp`, and allocates storage for the array.

Variables have to be defined _somewhere_; otherwise, we get linker errors.
When we're decompiling code with `extern` variables, the variables are
actually defined by [symbol_addrs.txt](config/US/symbol_addrs.txt).
This file maps each variable to its VRAM address/storage location in the
final binary, so the linker knows how to relocate variables.

#### Handling `float` literals

Some functions will make use of floating-point literals, like `3.1415927f`.
GCC pulls these out into the `.lit4` section, where they are referenced
as normal variables in the compiled code.

You won't be able to use literals in the code unless you've already migrated
the `.lit4` section, so you'll need to reference these as `extern float`s:

```c++
extern float D_004FA64C; // 0.0000001f

float mathfNormalize(FVECTOR* result, FVECTOR* vec)
{
    float norm = sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));

    if (norm < D_004FA64C) {
        result->x = 0.0f;
        result->y = 0.0f;
        result->z = 1.0f;
        return 0.0f;
    }

    // ...
}
```

However, the way GCC pulls these literals out can cause side effects in the codegen,
particularly if the literal is used near a branch delay slot:

```c++
extern float D_004FA670; // 0.0099999998f

float mathfPitchFromVector(FVECTOR* vec)
{
    float magnitude = mathfManhatDist(vec, NULL);

    if (magnitude == 0.0f) {
        magnitude = D_004FA670;
    }
    return atan2f(vec->z, magnitude);
}
```

```
TARGET                                                   CURRENT (230)
dbeb8:    mtc1    zero,$f1                               dbeb8:    mtc1    zero,$f1
dbebc:    nop                                            dbebc:    nop
dbec0:    c.eq.s  $f0,$f1                                dbec0:    c.eq.s  $f0,$f1
dbec4:    nop                                            dbec4:    nop
dbec8:    bc1f    dbed4 ~>                        |      dbec8:    bc1tl   dbed0 ~>
dbecc:    lwc1    $f12,8(s0)                      |      dbecc:    lwc1    $f0,-0x4800(gp)
dbed0:    lwc1    $f0,-0x4800(gp)                 |      dbed0: ~> lwc1    $f12,8(s0)
```

In this case, substituting the literal fixes the instruction swap and produces an exact match:

```c++
float mathfPitchFromVector(FVECTOR* vec)
{
    float magnitude = mathfManhatDist(vec, NULL);

    if (magnitude == 0.0f) {
        magnitude = 0.0099999998f;
    }
    return atan2f(vec->z, magnitude);
}
```

Unfortunately, there's usually no workaround for this problem. You'll have to comment these
functions out and wait until the `.lit4` section has been split, then add the literals.

#### Handling VU0 Instructions

TODO

#### Troubleshooting

Let's say we made a mistake in our C++ code from earlier, and used the struct
field at offset `0x2` instead:

```cpp
typedef struct {
    u8 unk[0x2];
    u16 field1_0x2;
    u16 field2_0x4;
    u8 unk2[0x1A];
} _fontInfo;

extern _fontInfo fontInfo[2];

void fontSetCharWidth(int param_1, int param_2)
{
    fontInfo[param_1].field1_0x2 = param_2;
}
```

Our mistake makes the new binary non-matching, and the `ninja` build will fail:

```
[4/5] CHECK       /workspace/build/SCUS_971.01
FAILED: /workspace/build/build.sha1
./configure.py check --binary /workspace/build/SCUS_971.01 --output /workspace/build/build.sha1
/workspace/build/SCUS_971.01: NONMATCHING
ninja: build stopped: subcommand failed.
```

How do we see what went wrong?

The repository includes a tool called `asm-differ` that can help with this. Assuming
we're in our Python virtual environment, we can run
`./tools/asm-differ/diff.py fontSetCharWidth__Fii`
in the terminal to get a nice view of the two binaries:

```
TARGET                                                   CURRENT (5)
c5380:    lui     v0,0x50                                c5380:    lui     v0,0x50
c5384:    sll     a0,a0,0x5                              c5384:    sll     a0,a0,0x5
c5388:    addiu   v0,v0,0x4540                           c5388:    addiu   v0,v0,0x4540
c538c:    addu    a0,a0,v0                               c538c:    addu    a0,a0,v0
c5390:    jr      ra                                     c5390:    jr      ra
c5394:    sh      a1,4(a0)                        i      c5394:    sh      a1,2(a0)
```

We can see the `sh` ("Store Half Word") instruction at the end of the function is
storing to `field1_0x2` instead of `field2_0x4`. (The diff view in the terminal has
colored text to better illustrate the difference.)

Once we fix our code up, we get a matching build again:

```
[4/5] CHECK       /workspace/build/SCUS_971.01
/workspace/build/SCUS_971.01: OK
```

### 3. Split/Disassemble Data

#### ELF Segments

Let's look at what data the ELF segments actually correspond to:

- `.rodata`
  - Generally contains jump tables and some constants (including const strings).
  - Example: `const char* foo = "test123";`
- `.data`
  - Contains non-constant variables defined with initial values.
    In TMB, most of the data here is large `struct`s and `array`s.
  - Example: `u8 foo[10] = { 0xDE, 0xAD, 0xBE, 0xEF, 0, 0, 0, 0, 0, 0 }`;
- `.sdata`
  - Same as `.data`, but all variables are 8 bytes or less in size.
  - Example: `int fontFirstFrame = 1;`
- `.bss`
  - Contains non-constant variables with _no initial value_.
    In TMB, most of the data here is large `struct`s and `array`s.
  - Example: `sceGsLoadImage fontLoadImage;`
- `.sbss`
  - Same as `.bss`, but all variables are 8 bytes or less in size.
  - Example: `int numFontSprites;`
- `.lit4`
  - Contains floating point literals which GCC decided were too much of a pain
    to load into the code directly.
    - Specifically **literals**, and not developer-defined variables.
  - Example: `if (foo < 0.000088886f) {`
    - The `0.000088886f` value would be found in the `.lit4` somewhere.
- `.vutext`
  - Contains data and code for the VU1 processor.
  - You should ignore this for now. Use `extern` to access any data here if you
    need it.

#### Splitting Segments

Thankfully, GCC makes this relatively easy on us. You can assume that
**all of the TU's data will be bunched up together**. For example, all of
`tmb/font.cpp`'s `sbss` variables will be grouped up somewhere inside of
the `.sbss` segment of the final binary.

Thus, when splitting a TU's data segment, you want to find two locations in
the binary:
1. The first variable from your TU in the data segment
2. The last variable from your TU in the data segment

You can reasonably assume that everything in-between should also be defined
in your TU.

The easiest way to do this is via Ghidra, as it allows you to check
function->variable references.

1. Open your Ghidra TMB project.
2. Look at some variables in your TU. For this example, we'll use `tmb/mathf.cpp`
   and try to split the `lit4` segment.
   We see that `mathfRPHFromMatrix()` uses a `float` literal located at
   VRAM `$004FA664`, image base `$3FA664`:
   ```
   FLOAT_004fa664        XREF[1]:     mathfRPHFromMatrix:001dbc64(R)
   004fa664 77 cc 2b 32     float      9.9999999E-9
   ```
3. Now that we're in the middle of `tmb/mathf.cpp`'s `lit4`, we can start scrolling
   up until we find the first variable _not_ used by a `mathf` function.
   ```
   FLOAT_004fa648        XREF[1]:     getLightVolWeight:001da0dc(R)
   004fa648 ab aa aa 3e     float      0.33333334
   FLOAT_004fa64c        XREF[1]:     mathfNormalize:001da7cc(R)
   004fa64c 95 bf d6 33     float      1.0E-7
   ```
   `getLightVolWeight()` is a function from `LightVolume.cpp`. So we know now that
   VRAM `$004FA64C`, image base `$3FA64C`, is the start of `tmb/mathf.cpp`'s `lit4` segment.
4. Similarly, we can scroll down to find the first variable _not_ used by a `mathf`
   function.
   ```
   FLOAT_004fa68c           XREF[1]:     mathfNormalizeQuaternionFromW:00
   004fa68c 95 bf d6 33     float      1.0E-7
   FLOAT_004fa690           XREF[1]:     utilGenerateRandomNormalizedVector
   004fa690 db 0f c9 40     float      6.2831855
   ```
   `utilGenerateRandomNormalizedVector()` is from `particle.cpp`. So we know now that
   VRAM `$004FA690`, image base `$3FA690`, is the end of `tmb/mathf.cpp`'s `lit4` segment.
5. Find `lit4` in our `splat` configuration.
   ```
      # ------------------------------------------------
      # .lit4 segment
      # ------------------------------------------------
      - [0x3F6E80, lit4]
   ```
6. Now that we know the borders, we can now split out `tmb/mathf`.
   ```
      # ------------------------------------------------
      # .lit4 segment
      # ------------------------------------------------
      - [0x3F6E80, lit4]
      - [0x3FA64C, lit4, tmb/mathf]
      - [0x3FA690, lit4]
   ```
   Replace `tmb/mathf` with your TU. (It should have the same name as the
   corresponding `cpp` segment.)
7. Re-generate the build system with
   `./configure.py distclean && ./configure.py generate`.

Global variables may be referenced in multiple TUs, which will cause some
ambiguity. Some global variables may not even be used in the location
they're defined. You might need to experiment if a global variable is
seemingly defined on a border.

#### `.data` vs `data`, `.lit4` vs `lit4`, etc.

It might not be clear what the difference between these two is in the `splat`
config. Which should you use, and when?

- `[name]` tells the linker that the **data is sourced from the original binary**.
  Even if we give it a name here (`tmb/mathf`, in the above case), the data is
  still taken from the original binary.
- `.[name]` tells the linker that the **data is sourced from the decompiled TU**.
  You don't want to use `.[name]` until you've [decompiled the data](#4-decompile-data)
  first.

### 4. Decompile Data

We've found our data section. How do we migrate it to the C++ code?

This will depend on the section type, but it's generally straightforward.

If you've already decompiled the code to C++ and you were using `extern`
on the variables, all you need to do is:
- Remove the `extern` qualifier
- Set the initial value of the variable, if it has one in the original binary.
  (Check [ELF Segments](#elf-segments) for more info on that.)
- Add the `static` qualifier if it's clearly not a global variable.

Once you've done this, simply change the `splat` segment type by adding a `.`
character in front of it:

```
      - [0x3FB840, .sdata, tmb/font]
```

Regenerate the build system with `./configure.py distclean && ./configure.py generate`.
When you compile with `ninja`, the data from your C++ file should now be linked into
the final binary. If you get `NONMATCHING` after this, you've likely declared
variables in the wrong order in your C++ file, or your variables have the incorrect
type/size.

#### `.rodata`

If you're here because your initial `cpp` split [wouldn't compile](#finding-rodata),
you need to verify whether the `rodata` segment actually contains `const` values.

You can check this simply by scrolling through the data.
- If the entire thing is composed of jump tables and addresses/pointers,
  you're in luck; all you need to do is change the `splat` segment name from
  `rodata` to `.rodata` and it should compile.
- If the section contains more than jump tables, you'll need to define those
  constants in the C++ file before you can compile.

#### `.lit4`

Because `.lit4` variables are actually literals and not developer-defined variables,
migrating them is a bit more effort. You'll have to replace the usage of your
`extern float` variables with the literals in each function, then hope everything
lines up.

## Matching Patterns

If you're having trouble matching code, you might want to check out the
[Decompedia page for GCC](https://decomp.wiki/en/compilers/GCC).

This page lists a large number of optimization patterns which GCC can
apply to the code, and may be helpful when dealing with particularly
stubborn mismatches (regalloc, extra registers, etc).
