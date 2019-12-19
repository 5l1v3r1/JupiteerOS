#include "../include/int_types.h"

/*The memset() function fills the first n bytes of the 
  memory area pointed to by s with the constant byte c.*/
void *memset(void *s, int c, size_t n) {
  char *m = (char*)s;

  for (size_t i=0; i<n; i++) 
    m[i] = (uint8_t)c;
  
  return s;
}
