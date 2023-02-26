VERSION = 0.1.0
NAME = Chicken soup

SUPPRESS_ECHO = 0
SUPPRESS_COMMAND = 1

#CFLAGS = -std=c18 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
#CFLAGS += -Wno-unused-parameter -Wno-pointer-arith
CFLAGS = -nostdlib -ffreestanding -no-pie -Wall -Wextra -Wpedantic -Wstrict-aliasing
LDFLAGS :=
MAKEFLAGS := --no-print-directory

CC = gcc
LD = gcc

#TODO: LOCATION = $(shell pwd) # below is user specific
LC = /home/chm46e/ap/josxter
LC_BIN = $(LC)/bin
LC_INITRD = $(LC)/initrd
LC_KERNEL = $(LC)/kernel
LC_MILKIT = $(LC)/milkit

QEMU_PERF_FLAGS = -vga virtio -m 1G
QEMU_ADD_KERN_FLAGS = loglevel=6

ifeq ($(SUPPRESS_COMMAND), 1)
	CQ = @
else
	CQ = 
endif

# All internal projects
include milkit/Makefile

# Qemu requirements
include initrd/Makefile
include kernel/Makefile

# Generic control
PHONY := all
all: info run

PHONY += info
info:
	@echo "VERSION: $(VERSION) '$(NAME)'"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"
	@echo "CC: $(CC)"
	@echo "LD: $(LD)"
	@echo "LC: $(LC)"
	@echo ""

# Generic compile for C file
# Suffix objs with: .o
%.o: %.c
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CC] $@";\
	fi
	$(CQ)$(CC) -o $@ -c $< $(CFLAGS)

# Generic compile for asm file
# Suffix objs with: _s.o
# (different suffix is required to differentiate from c file objects)
# (this isn't really an issue as asm file count is minimal)
%_s.o: %.S
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[AS] $@";\
	fi
	$(CQ)$(CC) -o $@ -c $< $(CFLAGS)

PHONY += clean
clean: milkit_clean kernel_clean initrd_clean

PHONY += exec
exec: kernel_update initrd_update
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[QEMU] qemu-system-x86_64 -kernel $(LC_KERNEL)/vmlinuz -initrd $(LC_INITRD)/initrd.img.cpio.gz $(QEMU_PERF_FLAGS) --append 'root=/dev/ram0 rw $(QEMU_ADD_KERN_FLAGS)'";\
	fi
	$(CQ)qemu-system-x86_64 -kernel $(LC_KERNEL)/vmlinuz -initrd $(LC_INITRD)/initrd.img.cpio.gz $(QEMU_PERF_FLAGS) --append "root=/dev/ram0 rw $(QEMU_ADD_KERN_FLAGS)"

PHONY += run
run: milkit_install exec

PHONY += build
build: milkit_build

.PHONY: $(PHONY)

