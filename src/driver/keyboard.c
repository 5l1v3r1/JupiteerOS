#include "keyboard.h"
#include "us_keyboard_map.h"
#include "../sys/isr.h"
#include "../sys/io.h"
#include "../include/tty.h"
#include "../include/int_types.h"

extern uint8_t us_keyboard_map[128];

void keyboard_handler(){
  uint8_t status;
  char scan_code;

  // 0x64: Keyboard status port
  status = inb(0x64);

  // Check the data, is it empty?
  if (status & 0x01) {
    // 0x60 : Keyboard data port
    scan_code = inb(0x60);

    char c = (us_keyboard_map[(uint8_t)scan_code]);
    put_char(c);
  
  }
  
}

void init_keyboard(){
  register_interrupt_handler(IRQ1, &keyboard_handler);
}