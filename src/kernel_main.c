#include "include/int_types.h"
#include "include/tty.h"
#include "sys/gdt.h"
#include "sys/idt.h"
#include "driver/keyboard.h"

int main(){
  clear_screen();
  init_gdt();
  init_idt();

  print("Welcome to JupiteerOS!");

  // Interrupts
  asm volatile ("int $0x3");
  asm volatile ("int $0x2");

  // Initialize keyboard
  init_keyboard();
  // Initialize prompt
  init_prompt();

  return 0;
}