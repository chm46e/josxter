#include "lib.h"

#include <include/stdlib.h>
#include <include/stddef.h>
#include <include/stdmem.h>

static char *itoa_alloc_prev;

/* copied from stack overflow hehe*/
extern char *itoa(int i){
    char const digit[] = "0123456789";
    char *b = malloc(50); /* trust me bro, it's safe */
    char* p = b;

    if (itoa_alloc_prev != NULL)
        free(itoa_alloc_prev);

    itoa_alloc_prev = b;

    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);

    return b;
}