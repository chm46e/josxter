#include "assert.h"

#include <include/stdlib.h>
#include <include/stdio.h>

/* 
 * this assert isn't quite how normally assert works
 * just checks for false and then exits
 * no fancy stuff
 * The real assert is much more connected to the compiler.
 *
 * assert should only be used for debugging
 * not for release ready stuff
 * but i'm not releasing anything, so ¯\_(ツ)_/¯
 */
extern void assert(int expression)
{
    if (expression <= 0) {
        printf("assert() failed\n");
        abort();
    }
}
