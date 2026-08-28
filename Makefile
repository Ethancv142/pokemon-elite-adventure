# Pokémon Elite Adventure - GBA ROM Build
# Using DevkitARM and libgba

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to devkitARM>")
endif

include $(DEVKITARM)/gba_rules

# Project name
TARGET := pokemon-elite-adventure
BUILD := build
SOURCES := src
DATA := data
INCLUDES := include
LIBS := -lm

# Source files
CSOURCES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPSOURCES := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SOBJECTS := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

COBJS := $(CSOURCES:%.c=$(BUILD)/%.o)
CPPOBJS := $(CPPSOURCES:%.cpp=$(BUILD)/%.o)
SOBJS := $(SOBJECTS:%.s=$(BUILD)/%.o)
OBJS := $(COBJS) $(CPPOBJS) $(SOBJS)

DEPFLAGS := -MMD -MP
CFLAGS := -Wall -O2 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math
ASFLAGS := -mcpu=arm7tdmi -mtune=arm7tdmi
LDFLAGS := -Wl,-Map,$(BUILD)/$(TARGET).map

all: $(BUILD)/$(TARGET).gba

$(BUILD):
	mkdir -p $@

$(BUILD)/%.o: $(SOURCES)/%.c | $(BUILD)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCLUDES) -c $< -o $@

$(BUILD)/%.o: $(SOURCES)/%.cpp | $(BUILD)
	$(CXX) $(CFLAGS) $(DEPFLAGS) -I$(INCLUDES) -c $< -o $@

$(BUILD)/%.o: $(SOURCES)/%.s | $(BUILD)
	$(AS) $(ASFLAGS) -c $< -o $@

$(BUILD)/$(TARGET).elf: $(OBJS)
	$(LD) $^ $(LDFLAGS) $(LIBS) -o $@

$(BUILD)/$(TARGET).gba: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(TOOL_STRIP) -s $@

clean:
	rm -rf $(BUILD)

.PHONY: all clean
