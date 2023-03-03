#pragma once

#include <include/stdtype.h>

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t num);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t num);
unsigned int strcmp(const char *stra, const char *strb);
unsigned int strncmp(const char *stra, const char *strb, size_t num);
const char *strchr(const char *str, int character);
size_t strcspn(const char *stra, const char *strb);
const char *strpbrk(const char *stra, const char *strb);
const char *strrchr(const char *str, int character);
size_t strspn(const char *stra, const char *strb);
const char *strstr(const char *stra, const char *strb);
char *strtok(char *str, const char *delimiters);
size_t strlen(char *str);

void *memcpy(void *dest, const void *src, size_t num);
unsigned int memcmp(const void *ptra, const void *ptrb, size_t num);
void *memchr(const void *ptr, int value, size_t num);
void *memset(void *ptr, int value, size_t num);
