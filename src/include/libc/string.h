#ifndef _STRING_H_
#define _STRING_H_

#include <libc/stdint.h>

void *memset(void *s, int c, size_t n);
char *itoa(int val, char *buf, int base);
int strlen(const char *s);
int printf(const char *format, ...);
int strcmp(const char *s1, const char *s2);

#endif // _STRING_H_ 