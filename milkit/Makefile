milkit-obj += milkit/main.o
milkit-sobj += milkit/start_s.o

milkit_build: bin/milkit 
bin/milkit: $(milkit-sobj) $(milkit-obj)
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[LD] $@";\
	fi
	$(CQ)$(LD) -o $(LC)/$@ $^ $(LDFLAGS) $(CFLAGS)

milkit_install: $(LC_INITRD)/mnt/usr/sbin/init
$(LC_INITRD)/mnt/usr/sbin/init: milkit_build
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[IN] $@";\
	fi
	$(CQ)cp -f $(LC_BIN)/milkit $(LC_INITRD)/mnt/usr/sbin/init

milkit_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(milkit-obj)
	$(CQ)rm -f $(milkit-sobj)
	$(CQ)rm -f $(LC_BIN)/milkit

