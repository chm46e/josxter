sniffit-obj += sniffit/main.o
sniffit-sobj += sniffit/start_s.o

sniffit_build: snufklib_build bin/sniffit 
bin/sniffit: $(sniffit-sobj) $(sniffit-obj)
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[LD] $@";\
	fi
	$(CQ)$(LD) -o $(LC)/$@ $^ $(LDFLAGS) $(CFLAGS) -Lbin -lsnufk

sniffit_install: $(LC_INITRD)/mnt/usr/sbin/init
$(LC_INITRD)/mnt/usr/sbin/init: sniffit_build
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[IN] $@";\
	fi
	$(CQ)cp -f $(LC_BIN)/sniffit $(LC_INITRD)/mnt/usr/sbin/init

sniffit_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(sniffit-obj)
	$(CQ)rm -f $(sniffit-sobj)
	$(CQ)rm -f $(LC_BIN)/sniffit

