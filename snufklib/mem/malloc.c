#include "malloc.h"

#include <include/snufklib/sys.h>
#include <include/stdio.h>
#include <include/stdtype.h>
#include <include/stddef.h>
#include <syscall.h>

/* 
 * Switch between brk and mmap.
 * static threshold to switch is 64 Kib
 */
#define MMAP_SWITCH_THRESHOLD 64 * 1024

/*
 * Support for both malloc allocation methods.
 * (brk isn't currently supported..)
 */
#define BRK_MALLOC_SUPPORT 0
#define MMAP_MALLOC_SUPPORT 1

/*
 * Generic header implementation
 * (not different between brk and mmap)
 *
 * mheader_size controls double free safety:
 * > 0 (allocated)
 * <= 0 (deallocated)
 */
struct malloc_header {
    int32_t mheader_size;
};
#define MALLOC_HEADER_SIZE 4

static int MALLOC_MMAP_DEFAULT_PROT = (PROT_READ | PROT_WRITE);
static int MALLOC_MMAP_DEFAULT_FLAGS = (MAP_PRIVATE | MAP_ANONYMOUS);

/*
 * malloc_mmap implementation:
 * (extern to support specific memory allocation control outside)
 *
 * This is super simple, as there is no control needed between multiple mmaps.
 * Just allocate for a header and required size and call it a day.
 *
 * From the man page for ease of use:
 * void *mmap(void addr[.length], size_t length, int prot, int flags,
 *            int fd, off_t offset);
 */
extern void *malloc_mmap(size_t size)
{
    int mchunk_size = size + MALLOC_HEADER_SIZE;
    void *p;
    struct malloc_header *ps;

    if (size <= 0) {
        printf("error: malloc size <= 0");
        return nullptr;
    }

    p = __sys_mmap(NULL, mchunk_size,
                   MALLOC_MMAP_DEFAULT_PROT, MALLOC_MMAP_DEFAULT_FLAGS,
                   0, 0);
    ps = (struct malloc_header *)p;

    ps->mheader_size = size;

    return (void *)(ps + 1);
}

extern void *malloc(size_t size)
{
    return malloc_mmap(size);
}

/*
 * free implementation:
 *
 * From the man page for ease of use:
 * int munmap(void addr[.length], size_t length);
 */

extern void free(void *ptr)
{
    int mchunk_size, rc; 
    void *p;
    struct malloc_header *ps = (struct malloc_header *)ptr - 1;
    p = (void *)ps;

    if (ps->mheader_size <= 0) {
        printf("error: attempt at double free!\n");
        return;
    }

    mchunk_size = ps->mheader_size;
    ps->mheader_size = -1;

    rc = __sys_munmap(p, mchunk_size);

    if (rc < 0) {
        printf("error: free failed \n");
    }
}




