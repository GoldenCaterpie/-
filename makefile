AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
CC=arm-none-eabi-gcc
ARS=armips
GRIT=grit

ASFLAGS=-mthumb
CFLAGS= -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2
LDFLAGS=-z muldefs

BLDPATH:=build

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ASSRC := $(call rwildcard,src/,*.s)
CSRC := $(call rwildcard,src/,*.c)
ASOBJS := $(ASSRC:%.s=$(BLDPATH)/%.o)
COBJS := $(CSRC:%.c=$(BLDPATH)/%.o)
OBJS:= $(COBJS) $(ASOBJS)

$(BLDPATH)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@

$(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) -c $< -o $@


all: $(OBJS)
	$(LD) $(LDFLAGS) -T linker.lsc -T bpee.ld --relocatable -o "build\linked.o" $(ASOBJS) $(COBJS)
	$(ARS) insert.asm
	