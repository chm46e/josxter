initrd_build_cpio: initrd/initrd.img.cpio
initrd/initrd.img.cpio:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[UP] $@";\
	fi
# cd ... is required for the initrd file structure to be correct (check with lsinitrd tool!)
# example of a good structure: sbin/init and bad structure: /home/chm46e/.../sbin/init
	$(CQ)cd $(LC_INITRD)/mnt/ && find . 2>/dev/null | cpio --create --format='newc' > $(LC_INITRD)/initrd.img.cpio

initrd_build_gzip: initrd_build_cpio initrd/initrd.img.cpio.gz
initrd/initrd.img.cpio.gz:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[UP] $@";\
	fi
	$(CQ)gzip -9 -k -f $(LC_INITRD)/initrd.img.cpio

PHONY += initrd_update
initrd_update: snufklib_install sniffit_install initrd_build_gzip

initrd_clean:
	@if [ !$(SUPPRESS_ECHO) ]; then\
		echo "[CLEAN] $@";\
	fi
	$(CQ)rm -f $(LC_INITRD)/initrd.img.cpio.gz
	$(CQ)rm -f $(LC_INITRD)/initrd.img.cpio
