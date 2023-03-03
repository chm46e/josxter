include snufklib/io/Makefile
include snufklib/kernel/Makefile
include snufklib/mem/Makefile
include snufklib/lib/Makefile

snufklib_build: bin/libsnufk.a
bin/libsnufk.a: $(snufklib-sobj) $(snufklib-obj)
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[AR] $@";\
	fi
	$(CQ)$(AR) rcs $(LC)/$@ $^ $(ARFLAGS)

snufklib_install: $(LC_INITRD)/mnt/usr/lib/libsnufk.a
$(LC_INITRD)/mnt/usr/lib/libsnufk.a: snufklib_build
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[IN] $@";\
	fi
	$(CQ)cp -f $(LC_BIN)/libsnufk.a $(LC_INITRD)/mnt/usr/lib/libsnufk.a

snufklib_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(snufklib-obj)
	$(CQ)rm -f $(snufklib-sobj)
	$(CQ)rm -f $(LC_BIN)/libsnufk.a

