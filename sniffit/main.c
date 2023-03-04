#include <include/stdlib.h>
#include <include/stdmem.h>
#include <include/stdio.h>

int main()
{
    printf("running..\n");
    int *ptr = malloc_mmap(100);

    free(ptr);

    while (1) {
         
    }
    return 0;
}
