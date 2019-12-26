#ifndef _STRING_H_
#define _STRING_H_

#include "../include/int_types.h"
#include "string.h"

void *memset(void *s, int c, size_t n);
char *itoa(int val, char *buf, int base);

#endif /* _STRING_H_ */
