#include "isr.h"
#include "../include/string.h"
#include "../include/tty.h"

void isr_handler(registers_t regs){
  char buf[3]; // "0" - "255"
  print("\nReceived interrupt no:");
  print(itoa(regs.int_no, buf, 10));
}
