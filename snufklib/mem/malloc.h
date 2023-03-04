#pragma once

#include <include/stdtype.h>

/* taken from /usr/include/bits/mman-linux.h */

/* Protections are chosen from these bits, OR'd together.  The
   implementation does not necessarily support PROT_EXEC or PROT_WRITE
   without PROT_READ.  The only guarantees are that no writing will be
   allowed without PROT_WRITE and no access will be allowed for PROT_NONE. */

#define PROT_READ	0x1		/* Page can be read.  */
#define PROT_WRITE	0x2		/* Page can be written.  */
#define PROT_EXEC	0x4		/* Page can be executed.  */
#define PROT_NONE	0x0		/* Page can not be accessed.  */

/* Sharing types (must choose one and only one of these).  */
#define MAP_SHARED	0x01		/* Share changes.  */
#define MAP_PRIVATE	0x02		/* Changes are private.  */

/* Other flags.  */
#define MAP_FIXED	0x10		/* Interpret addr exactly.  */
#define MAP_FILE	0
#define MAP_ANONYMOUS	0x20		/* Don't use a file.  */

extern void *malloc_mmap(size_t size);
extern void *malloc(size_t size);
extern void free(void *ptr);
