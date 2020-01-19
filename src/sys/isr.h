#ifndef __ISR_H__
#define __ISR_H__

#include "../include/int_types.h"

#define MASTER_PIC_COMMAND	0x20  
#define MASTER_PIC_DATA     0x21 
#define SLAVE_PIC_COMMAND   0xA0
#define SLAVE_PIC_DATA   	  0xA1
// End-of-interrupt command code
#define PIC_EOI         		0x20    

typedef struct registers{
	// Data segment selector
	uint32_t ds;
	// Pushed by pusha.
	uint32_t edi,esi,ebp,esp,ebx,edx,ecx,eax; 
	// Interrupt number and error code.
	uint32_t int_no,err_code;
	// Pushed by the processor automatically.
	uint32_t eip,cs,eflags,useresp,ss; 
} registers_t;

typedef void (*isr_t)(registers_t);

#endif // __ISR_H__