LINUX = kernel/linux
LINUX_BZIMAGE = $(LINUX)/arch/x86/boot/bzImage

PHONY += kernel_update
kernel_update: kernel/vmlinuz

kernel/vmlinuz: $(LINUX_BZIMAGE)
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[UP] $@";\
	fi
	@#TODO: Check for missing bzImage
	$(CQ)cp -f $(LINUX_BZIMAGE) $(LC_KERNEL)/vmlinuz

kernel_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(LC_KERNEL)/vmlinuz
