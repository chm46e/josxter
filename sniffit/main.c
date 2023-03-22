#include <include/stdlib.h>
#include <include/stddef.h>
#include <include/stdmem.h>
#include <include/stdio.h>

static const char *jonksh_argv[] = {"/sbin/jonksh", NULL};

int main()
{
    exec(jonksh_argv);

    while (1) {
         
    }
    return 0;
}
