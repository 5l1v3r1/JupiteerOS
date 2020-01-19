#include "isr.h"
#include "../include/string.h"
#include "../include/tty.h"
#include "io.h"

isr_t interrupt_handlers[256];

void isr_handler(registers_t regs){
  char buf[3]; // "0" - "255"
  print("\nReceived interrupt no:");
  print(itoa(regs.int_no, buf, 10));
}

void irq_handler(registers_t regs){
	/* If interrupt number > 40), we send a reset signal to the slave. 
	In either case, we send one to the master also. */

	if (regs.int_no >= 40){
		outb(SLAVE_PIC_COMMAND, PIC_EOI);
	}

	outb(MASTER_PIC_COMMAND, PIC_EOI);

	if (interrupt_handlers[regs.int_no] != 0){
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}

}