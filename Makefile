TARGET ?= puzzle_bobble
MODULE ?= BOOT

BUILD   := tmp/build/$(TARGET)
TOOLS   := tmp/toolchains/bin
PYTHON  := .venv/bin/python

BASEROM := tmp/baserom/$(TARGET)/$(MODULE).prx
CONFIG  := config/$(TARGET)/$(MODULE).yaml
UNITS   := config/$(TARGET)/units.$(MODULE).txt
LD_SCRIPT := $(BUILD)/$(MODULE).ld
ELF     := $(BUILD)/$(MODULE).elf
OUT     := $(BUILD)/$(MODULE).prx

AS      := $(TOOLS)/mips-as
LD      := $(TOOLS)/mips-ld
OBJCOPY := $(TOOLS)/mips-objcopy
PSP_AS  := $(TOOLS)/psp-as
CPP     := cpp

ASFLAGS := -EL -march=allegrex -G0 --no-pad-sections -Iinclude
CPPFLAGS := -P -undef -nostdinc -Iinclude -Iinclude/sdk -Iinclude/libc -Idecomp_src -D__GNUC__=3 -D_LANGUAGE_C -D__psp__ -D__mips__ $(EXTRA_CPPFLAGS)
CFLAGS  := -G0 -quiet

S_FILES   = $(shell find tmp/asm/$(TARGET)/$(MODULE) -name '*.s' -not -path '*/nonmatchings/*' 2>/dev/null)
C_FILES   = $(shell grep -oE 'decomp_src/[^ ()]+\.c' $(LD_SCRIPT) 2>/dev/null | sort -u)
BIN_FILES = $(wildcard tmp/assets/$(TARGET)/$(MODULE)/*.bin)
O_FILES   = $(foreach f,$(S_FILES) $(C_FILES) $(BIN_FILES),$(BUILD)/$(f).o)

# The compiler of a unit: the version in units.MODULE.txt, mapped by
# config/compilers.txt to a cc1 in tmp/toolchains/bin.
unit_of = $(patsubst decomp_src/$(TARGET)/$(MODULE)/%.c,%,$(1))
cc1_of  = $(TOOLS)/$(shell $(PYTHON) tools/compiler.py --prog $(TARGET) $(MODULE) $(call unit_of,$(1))) $(shell $(PYTHON) tools/compiler.py --flags $(TARGET) $(MODULE) $(call unit_of,$(1)))
as_of   = $(PSP_AS) $(shell $(PYTHON) tools/compiler.py --as-flags $(TARGET) $(MODULE) $(call unit_of,$(1)))

.PHONY: all extract split clean distclean toolchain
.DEFAULT_GOAL := all
SHELL := /bin/bash

all: $(OUT)
	@sha1sum -c config/$(TARGET)/$(MODULE).sha1 --quiet <(sed 's#tmp/baserom/#tmp/build/#' config/$(TARGET)/$(MODULE).sha1) \
		&& echo "$(OUT): OK" || (echo "$(OUT): MISMATCH"; false)

toolchain:
	tools/setup_toolchain.sh
	tools/build_gcc.sh 1.5.1
	tools/build_gcc.sh 1.6.1

$(BASEROM):
	$(PYTHON) tools/modules.py $(TARGET) $(MODULE)

extract: $(BASEROM)

split: $(BASEROM)
	rm -rf $(BUILD)/.splat_cache.$(MODULE) tmp/asm/$(TARGET)/$(MODULE)
	$(PYTHON) tools/prx_relocs.py $(BASEROM) $(BUILD)/reloc_addrs.$(MODULE).txt $(BUILD)/prx_syms.$(MODULE).txt --names config/$(TARGET)/symbol_addrs.$(MODULE).txt
	$(PYTHON) tools/split.py $(CONFIG)
	@# the .s files of INCLUDE_ASM/INCLUDE_RODATA are new: rebuild the units that include them
	@grep -rlE '^INCLUDE_(ASM|RODATA)' decomp_src/$(TARGET)/$(MODULE) --include='*.c' | sed 's#^#$(BUILD)/#; s#$$#.o#' | xargs -r rm -f

$(BUILD)/%.s.o: %.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<
	$(PYTHON) tools/fix_old_gas.py --text-align 4 --data-align 4 $@

$(BUILD)/%.bin.o: %.bin
	@mkdir -p $(@D)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips:allegrex $< $@

$(BUILD)/%.c.o: %.c $(UNITS)
	@mkdir -p $(@D)
	$$(u=$$(grep -oP '^/\* upstream: \K(newlib|libgcc)' $<) && echo tools/$${u/newlib/nl}cpp.sh || echo '$(CPP) $(shell $(PYTHON) tools/compiler.py --cppflags $(TARGET) $(MODULE) $(call unit_of,$<)) $(CPPFLAGS) -MMD -MP -MF $(BUILD)/$*.c.d -MT $@') $< | $$(n=$$(grep -oP '^/\* srcname: \K\S+(?= \*/)' $<) && echo "$(PYTHON) tools/cc1name.py $$n") $(call cc1_of,$<) $$(grep -oP "cflags: \K-O[0-9s](?: +-(?:[fm][\w-]+|std)(?:=[\w.:]+)?)*" $< || echo -O2) $(CFLAGS) -o $(BUILD)/$*.c.s
	[ -z "$$($(PYTHON) tools/compiler.py --locfix $(TARGET) $(MODULE) $(call unit_of,$<))" ] || $(PYTHON) tools/locfix.py $(BUILD)/$*.c.s
	$(call as_of,$<) -EL -G0 -Iinclude -o $@ $(BUILD)/$*.c.s
	$(PYTHON) tools/fix_old_gas.py --text-align $$(grep -oP "text-align: \K[0-9]+" $< || echo 4) --data-align $$(grep -oP "data-align: \K[0-9]+" $< || echo 4) $@

$(ELF): $(O_FILES) $(LD_SCRIPT)
	$(LD) -EL -T $(LD_SCRIPT) -T $(BUILD)/undefined_syms_auto.$(MODULE).txt -T $(BUILD)/undefined_funcs_auto.$(MODULE).txt -T $(BUILD)/abs_syms.$(MODULE).txt -Map $(BUILD)/$(MODULE).map -o $@

$(OUT): $(ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf $(BUILD)/tmp $(BUILD)/decomp_src $(ELF) $(OUT)

distclean:
	rm -rf tmp/build tmp/asm tmp/assets

# header dependencies of the C units (cpp -MMD)
-include $(patsubst %.c.o,%.c.d,$(filter %.c.o,$(O_FILES)))
