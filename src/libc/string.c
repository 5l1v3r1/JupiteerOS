#include <libc/stddef.h>
#include <libc/stdint.h>
#include <libc/stdarg.h>
#include <kernel/tty.h>

/* The memset() function fills the first n bytes of the
 * memory area pointed to by s with the constant byte c.*/
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

  while (s[i] != '\0') i++;
  
  return i;
}

int printf(const char *format, ...){
  char buf[20],c,*s;
  int val;

  /* ap is the object of va_list and it will hold the 
   * information needed to retrieve the additional arguments with va_arg */
  va_list ap;

  va_start(ap, format);
  
  /* d,i => int; decimal number
   * x => int; unsigned hexadecimal number
   * c => int; single character
   * s => char *; print characters from the string until a '\0' 
   * or the number of characters given by the precision.
   */

  for (int i=0; i < strlen(format); i++){
    if (format[i] == '%'){
      i++;
      switch(format[i]){
        case 'i':
          val = va_arg(ap, int);
          itoa(val, buf, 10);
          print(buf);
          break;
        case 'x':
          val = va_arg(ap, uint32_t);
          itoa(val, buf, 16);
          print(buf);
          break;
        case 'd':
          val = va_arg(ap, uint32_t);
          itoa(val, buf, 10);
          print(buf);
          break;
        case 'c':
          c = (char)va_arg(ap, int);
          print_char(c);
          break;
        case 's':
          s = va_arg(ap, char*);
          print(s);
          break;
        default:
          print_char(format[i]);
      }
    } 
    else {
      print_char(format[i]);
    }
  }

  va_end(ap);
  return 0;
}