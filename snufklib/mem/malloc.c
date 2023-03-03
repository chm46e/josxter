#include "malloc.h"

#include <include/snufklib/sys.h>
#include <include/stdtype.h>
#include <include/stddef.h>
#include <syscall.h>

#define MMAP_HEADER_SIZE 4
#define MMAP_FLAG_ALLOC 1

/*
 * MMAP HEADER
 *   size: 31 bits
 *   flags: 1 bits
 *
 * MMAP CHUNK
 *   header: 4 bytes
 *   data: x
 */

void *malloc(size_t size)
{
    if (size <= 0)
        return 0;

    /* allocate entire mmap chunk */
    uint32_t *ptr = __sys_mmap(NULL, size + MMAP_HEADER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    *ptr = size;
    *ptr |= MMAP_FLAG_ALLOC; 
    
    return ptr + MMAP_HEADER_SIZE;
}

void free(void *ptr)
{
    ptr = (uint32_t *)ptr - MMAP_HEADER_SIZE;
   
    if (!(*((uint32_t *)ptr) & MMAP_FLAG_ALLOC))
        return;

    __sys_munmap(ptr, (*((uint32_t *)ptr) & 0xFFFFFFF8) + MMAP_HEADER_SIZE);

    /* clear header to not allow duplicate frees */
    *((uint32_t *)ptr) &= 0;
}
