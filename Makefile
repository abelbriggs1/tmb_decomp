### Build Options ###

VERSION      ?= US
EXEPATH      := disks
COMPARE      ?= 1
NON_MATCHING ?= 0
VERBOSE      ?= 0
BUILD_DIR    ?= build

ifeq ($(VERSION),US)
BASEEXE      := SCUS_971.01
endif

TARGET       := ${BASEEXE}
SPLAT_DIR    := config/$(VERSION)

# Fail early if baserom does not exist
ifeq ($(wildcard $(EXEPATH)/$(BASEEXE)),)
$(error Baserom `$(EXEPATH)/$(BASEEXE)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif

ifeq ($(OS),Windows_NT)
  DETECTED_OS=windows
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS=linux
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS=macos
    MAKE=gmake
    CPPFLAGS += -xc++
  endif
endif

### Output ###

EXE          := $(BUILD_DIR)/$(TARGET).elf.final
ELF          := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT    := $(SPLAT_DIR)/$(TARGET).ld
LD_MAP       := $(BUILD_DIR)/$(TARGET).map

### Tools ###

PYTHON     := python3
SPLAT_YAML := $(SPLAT_DIR)/$(BASEEXE).yaml
SPLAT      := splat split $(SPLAT_YAML)
DIFF       := diff

# For the actual compilers.
CROSSC   := tools/ee-gcc2.9/
# For binutils / linkers.
CROSSB   := mips-linux-gnu-

CC       := $(CROSSC)bin/ee-gcc
CXX      := $(CROSSC)bin/ee-gcc
CC1      := $(CROSSC)lib/gcc-lib/ee/2.9-ee-991111-01/cc1
AS       := $(CROSSB)as
LD       := $(CROSSB)ld
OBJCOPY  := $(CROSSB)objcopy
STRIP    := $(CROSSB)strip
CPP      := $(CROSSB)cpp

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
 PURPLE    := \033[0;35m
 ENDPURPLE := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###
ASFLAGS        := -EL -Iinclude -march=5900 -G0 -no-pad-sections -mabi=eabi
CFLAGS         := -O2 -G8 -Iinclude
CXXFLAGS       := -O2 -G8 -x c++ -Iinclude
LDFLAGS        := -EL -T $(SPLAT_DIR)/undefined_syms_auto.txt -T $(SPLAT_DIR)/undefined_funcs.txt -T $(LD_SCRIPT) -Map $(LD_MAP) -nostdlib

ifeq ($(NON_MATCHING),1)
CPPFLAGS += -DNON_MATCHING
endif

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' $(LD_SCRIPT) -o)
OBJECTS := $(OBJECTS:BUILD_PATH/%=$(BUILD_DIR)/%)
DEPENDS := $(OBJECTS:=.d)

### Targets ###

all: $(EXE)

-include $(DEPENDS)

clean:
	$(V)rm -rf $(BUILD_DIR)

distclean: clean
	$(V)rm -f $(LD_SCRIPT)
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -rf *_auto.txt

setup: distclean split

split:
	$(V)$(SPLAT)

# Compile .c files
$(BUILD_DIR)/%.c.o: %.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
# WRITE compiler command here

# Compile .s files
$(BUILD_DIR)/%.s.o: %.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final elf
$(EXE): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating EXE: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
ifeq ($(COMPARE),1)
	@$(DIFF) $(EXEPATH)/$(BASEEXE) $(EXE) && printf "OK\n" || (echo 'The build succeeded, but did not match the base EXE. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

### Make Settings ###

.PHONY: all clean distclean setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
