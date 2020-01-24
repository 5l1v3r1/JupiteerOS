#include "include/int_types.h"
#include "include/tty.h"
#include "sys/gdt.h"
#include "sys/idt.h"
#include "driver/keyboard.h"
#include "sys/timer.h"

int main(){
  clear_screen();
  init_gdt();
  init_idt();

  print("\nWelcome to JupiteerOS!");

  // Interrupts
  asm volatile ("int $0x3");
  asm volatile ("int $0x2");

  clear_screen();

  // Initialize keyboard
  init_keyboard();
  // Initialize prompt
  init_prompt();
  // Sleep 20 second
  sleep(20);

  return 0;
}