/*
 * Functions that manipulate cstrings and arrays
 * docs: https://cplusplus.com/reference/cstring/
 */

#include "string.h"

#include <include/stdtype.h>
#include <include/stddef.h>

/*
 * Copies src cstring to dest cstring
 * Returns dest
 */
char *strcpy(char *dest, const char *src)
{
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

/*
 * Copies num bytes of src to dest
 * Returns dest
 */
char *strncpy(char *dest, const char *src, size_t num)
{
    size_t i;

    for (i = 0; src[i] != '\0' && i < num; i++)
        dest[i] = src[i];
    for (; i < num; i++)
        /* if num hasn't been reached yet, fill with \0 until num */
        dest[i] = '\0';
    return dest;
}

/*
 * Concatenates src cstring to dest cstring
 * (overwrites dest \0 and appends it back at the end)
 * Returns dest
 */
char *strcat(char *dest, const char *src)
{
    size_t dlen = strlen(dest);
    size_t slen = strlen((char *)src);
    size_t i;

    for (i = 0; i < slen; i++) {
        dest[dlen + i] = src[i];
    }
    dest[i + 1] = '\0';
    return dest;
}

/*
 * Concatenates first num bytes of src to dest
 * (if num is bigger than src, then copy only up to \0)
 * Returns dest
 */
char *strncat(char *dest, const char *src, size_t num)
{
    size_t dlen = strlen(dest);
    size_t slen = strlen((char *)src);
    size_t i;

    for (i = 0; i < num && i < slen; i++) {
        dest[dlen + i] = src[i];
    }
    dest[i + 1] = '\0';
    return dest;
}

/*
 * Compares stra and strb
 * !Difference to standard:
 *   No higher/lower last value compare
 * Returns 0 if same or 1 if different
 */
unsigned int strcmp(const char *stra, const char *strb)
{
    for (size_t i = 0; stra[i] != '\0' && strb[i] != '\0'; i++) {
        if (stra[i] != strb[i])
            return 1;
    }
    return 0;
}
/*
 * Compares num bytes between stra and strb
 * !Difference to standard:
 *   No higher/lower last value compare
 * Returns 0 if same or 1 if different
 */
unsigned int strncmp(const char *stra, const char *strb, size_t num)
{
    for (size_t i = 0; i < num && stra[i] != '\0' && strb[i] != '\0'; i++) {
        if (stra[i] != strb[i])
            return 1;
    }
    return 0;
}

/*
 * Locate first occurence of character in str
 * Returns ptr to char or nullptr
 */
const char *strchr(const char *str, int character)
{
    size_t len = strlen((char *)str);

    for (size_t i = 0; i < len+1; i++) {
        if (str[i] == (char)character)
            return str + i;
    }
    return nullptr;
}

/*
 * Get span until char in strb matches char in stra
 * Time complexity: O(n**2) (could make it better, but it works)
 * Returns span if found or length if not found
 */
size_t strcspn(const char *stra, const char *strb)
{
    for (size_t i = 0; stra[i] != '\0'; i++) {
        for (size_t j = 0; strb[j] != '\0'; j++) {
            if (stra[i] == strb[i])
                return i+1;
        }
    }
    return strlen((char *)stra);
}

/*
 * Get pointer to first occurence of any char in strb to stra
 * (Similar to strcspn, except for return value)
 * Time complexity: O(n**2) (it works and that's what matters:D)
 * Returns ptr if found or nullptr if not found
 */
const char *strpbrk(const char *stra, const char *strb)
{
    for (size_t i = 0; stra[i] != '\0'; i++) {
        for (size_t j = 0; strb[j] != '\0'; j++) {
            if (stra[i] == strb[i])
                return stra + i;
        }
    }
    return nullptr;
}

/*
 * Locate last occurence of character in str
 * Returns ptr to char or nullptr
 */
const char *strrchr(const char *str, int character)
{
    for (size_t i = strlen((char *)str);; i--) {
        if (str[i] == (char)character)
            return str + i;
    }
    return nullptr;
}

/*
 * Get span of stra, which only consists of strb characters
 * The implementation is a little scuffed with gotos hehe
 * Returns length
 */
size_t strspn(const char *stra, const char *strb)
{
    size_t len = 0;

    for (size_t i = 0; stra[i] != '\0'; i++) {
        for (size_t j = 0; strb[j] != '\0'; j++) {
            if (stra[i] == strb[j]) {
                len++;
                goto next;
            }
        }
        break;
    next:
        continue;
    }
    return len;
}

/*
 * Get ptr to first occurence of string strb being fully in stra
 * Yea, gotos aren't the best thing, but they work..
 * Returns ptr or nullptr if not found
 */
const char *strstr(const char *stra, const char *strb)
{
    for (size_t i = 0; stra[i] != '\0'; i++) {
        if (stra[i] == strb[0]) {
            for (size_t j = 1; stra[i] != '\0' && strb[i] != '\0'; j++) {
                if (stra[i + j] != strb[j])
                    goto next;
            }
            return stra + i;
        }
    next:
        continue;
    }
    return nullptr;
}

/*
 * Sensibly yoinked from:
 * https://stackoverflow.com/questions/28931379/implementation-of-strtok-function
 */
static char *oldstr;
char *strtok(char *str, const char *delimiters)
{
    char *token;

    if (str == NULL)
        str = oldstr;

    /* Scan leading delimiters.  */
    str += strspn(str, delimiters);
    if (*str == '\0') {
        oldstr = str;
        return NULL;
    }
    /* Find the end of the token.  */
    token = str;
    str = (char *)strpbrk(token, delimiters);
    if (str == NULL) {
        /* This token finishes the string.  */
        oldstr = memchr(token, '\0', strlen(token));
    } else {
        /* Terminate the token and make OLDSTR point past it.  */
        *str = '\0';
        oldstr = str + 1;
    }
    return token;
}

/*
 * Get length of str
 * Returns length (without \0)
 */
size_t strlen(char *str)
{
    size_t len = 0; 

    while(*str++ != '\0')
        len++;
    return len;
}

/*
 * Copies num bytes from src to dest 
 * Returns destination
 */
void *memcpy(void *dest, const void *src, size_t num)
{
    for (size_t i = 0; i < num; i++)
        ((char *)dest)[i] = ((char *)src)[i];
    return dest;
}

/*
 * Compares num bytes between ptra and ptrb
 * !Difference to standard:
 *   No higher/lower last value compare
 * Returns 0 if same or 1 if different
 */
unsigned int memcmp(const void *ptra, const void *ptrb, size_t num)
{
    for (size_t i = 0; i < num; i++) {
        if (((char *)ptra)[i] != ((char *)ptrb)[i])
            return 1;
    }
    return 0;
}

/*
 * Locate value in ptr memory
 * Returns ptr to value or nullptr
 */
void *memchr(const void *ptr, int value, size_t num)
{
    for (size_t i = 0; i < num; i++) {
        if (((unsigned char *)ptr)[i] == (unsigned char)value) {
            return (void *)((int32_t *)ptr + i);
        }
    }
    return nullptr;
}

/*
 * Set first num bytes of ptr memory to value
 * Returns ptr (always)
 */
void *memset(void *ptr, int value, size_t num)
{
    for (size_t i = 0; i < num; i++) {
        ((unsigned char *)ptr)[i] = (unsigned char)value;
    }
    return ptr;
}
