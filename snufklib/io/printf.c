#include <include/snufklib/sys.h>
#include <include/stdio.h>
#include <include/stdlib.h>

int printf(const char *format)
{
    int console = __sys_open("/dev/stdout", O_WRONLY | O_NDELAY, 0);
    __sys_write(console, format, strlen((char *)format));
    __sys_close(console);
}
