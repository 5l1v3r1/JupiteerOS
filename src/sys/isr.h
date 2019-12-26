#ifndef __ISR_H__
#define __ISR_H__

#include "../include/int_types.h"

typedef struct registers{
   // Data segment selector
   uint32_t ds;
   // Pushed by pusha.
   uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 
   // Interrupt number and error code.
   uint32_t int_no, err_code;
   // Pushed by the processor automatically.
   uint32_t eip, cs, eflags, useresp, ss; 
} registers_t;

#endif // __ISR_H__
