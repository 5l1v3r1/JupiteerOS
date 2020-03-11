#include <libc/stddef.h>
#include <libc/stdint.h>

/*The memset() function fills the first n bytes of the
  memory area pointed to by s with the constant byte c.*/
void *memset(void *s, int c, size_t n) {
  char *m = (char *)s;

  for (size_t i = 0; i < n; i++)
    m[i] = (uint8_t)c;

  return s;
}

// The itoa() function converts an integer to a string.
char *itoa(int val, char *buf, int base) {
  static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  char *str = buf, temp;
  int sign;

  // Sign
  if ((sign = val) < 0)
    val = -val;

  // Convert
  do {
    *str++ = num[val % base];
  } while (val /= base);

  if (sign < 0)
    *str++ = '-';

  // End of the string
  *str = '\0';

  char *end = str - 1;
  char *begin = buf;

  // Reverse string
  while (end > begin) {
    temp = *end;
    *end-- = *begin;
    *begin++ = temp;
  }

  return buf;
}

int strlen(const char *s) {
  int i = 0;

  while (s[i] != '\0') {
    i++;
  }

  return i;
}