#include "printf.h"

#include <include/stdio.h>
#include <include/stdlib.h>
#include <include/stddef.h>

/* works more like c++ std::cout */
extern int printf(const char *format)
{
    FILE console = open("/dev/stdout", O_WRONLY | O_APPEND, 0);

    assert(console != NULL);

    write(console, format, strlen(format));
    close(console);

    return 0;
}
