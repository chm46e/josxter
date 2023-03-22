jonksh-obj += jonksh/jonksh.o
jonksh-sobj += jonksh/main_s.o

jonksh_build: snufklib_build bin/jonksh
bin/jonksh: $(jonksh-sobj) $(jonksh-obj)
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[LD] $@";\
	fi
	$(CQ)$(LD) -o $(LC)/$@ $^ $(LDFLAGS) $(CFLAGS) -Lbin -lsnufk

jonksh_install: $(LC_INITRD)/mnt/usr/sbin/jonksh
$(LC_INITRD)/mnt/usr/sbin/jonksh: jonksh_build
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[IN] $@";\
	fi
	$(CQ)cp -f $(LC_BIN)/jonksh $(LC_INITRD)/mnt/usr/sbin/jonksh

jonksh_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(jonksh-obj)
	$(CQ)rm -f $(LC_BIN)/jonksh

