# Contributing

## Developer Setup

### Option 1: Standard (Debian/Ubuntu)

If you are natively running in a Debian/Ubuntu (or WSL2) environment, then you can simply
install the required packages as detailed in [Requirements](README.md#requirements), then proceed with development.

### Option 2: VSCode w/ Docker Dev Container (**Recommended**)

If you are not running Debian/Ubuntu, you can use Visual Studio Code with the
"Dev Containers" extension installed. This repository has full support for devcontainers.

1. Install Docker and Visual Studio Code.
2. Install the "Dev Containers" extension in VSCode.
3. Open the repository in VSCode.
4. Use `Ctrl+Shift+P` to open the command palette.
5. In the command palette, search for the `Dev Containers: Rebuild Container` command and run it.

If everything goes well, you should now have a completely isolated environment for
development. The environment will be automatically set up with all dependencies installed,
and VSCode will automatically activate your Python virtual environment in your terminal
windows.

Since the development environment is completely isolated from your system, this is
the recommended development setup.

## Repository Layout

- `.devcontainer/`
  - Contains the VSCode "Dev Containers" extension configuration and Dockerfile.
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

## General Workflow

The following is a description of the general workflow a developer will use when
decompiling a translation unit (TU). This workflow should be fleshed out more in
the future to make it easier for others to contribute.

### 1. Split / Migrate Code

In the `splat` config file, `config/US/SCUS_971.01.yaml`, we need to find a translation
unit we want to decompile.

Let's say we want to decompile `tmb/font.cpp`. Since this file's code hasn't been decompiled
yet, it should have a subsegment type of `asm`:

```yaml
  - name: main
    type: code
    start: 0x1000
    vram: 0x00100000
    bss_size: 0x255E1C
    align: 4
    subalign: 4
    subsegments:
      # ------------------------------------------------
      # .text segment (C/C++ code)
      # ------------------------------------------------
      - [0x1000, asm, gcc/_crt0]
      - [0x10C0, asm, tmb/ai]

      # ...

      - [0xC4E48, asm, tmb/font]

      # ...
```

To decompile this as C++, we need to change the subsegment type to `cpp`:

```yaml
      - [0xC4E48, cpp, tmb/font]
```

Now that we've changed the `splat` config, we need to rerun `splat` and regenerate
our Ninja build script. This can be done with `./configure.py generate` in the root
of the repository.

After running `./configure.py generate`, we should have a new file in the `src/`
directory, `src/tmb/font.cpp`:

```cpp
#include "common.h"

INCLUDE_ASM("/workspace/asm/nonmatchings/tmb/font", fontInit__F10_vramAddrs);

INCLUDE_ASM("/workspace/asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

INCLUDE_ASM("/workspace/asm/nonmatchings/tmb/font", fontSetColorGifTag__Fi);

INCLUDE_ASM("/workspace/asm/nonmatchings/tmb/font", fontDimColor__Fi);

INCLUDE_ASM("/workspace/asm/nonmatchings/tmb/font", fontSetHilightColor__Fi);

// ...
```

`splat` generates this new C++ file for us. Currently, it's using a bunch of preprocessor
macros to directly include MIPS R5900 assembly code into the C++ file.

If we run `ninja` to build the repository, the binary should still match at this point.

```
[4/5] CHECK       /workspace/build/SCUS_971.01
/workspace/build/SCUS_971.01: OK
```

### 2. Decompile Code

Now that we have a C++ file that's being included in the build, we need to replace
the included assembly code with C++ code.

**NOTE**: Currently, the repository doesn't include a decompiler to make this process easier.
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
we're in our Python virtual environment, we can run `asm-differ fontSetCharWidth__Fii`
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

TODO

### 4. Decompile Data

TODO
