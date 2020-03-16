#include <drivers/keyboard.h>
#include <kernel/tty.h>
#include <libc/stdint.h>
#include <sys/gdt.h>
#include <sys/idt.h>
#include <sys/timer.h>
#include <libc/string.h>

int main() {
  clear_screen();
  init_gdt();
  init_idt();

  char str[23] = "Welcome to JupiteerOS!";
  printf("%s",str);

  // Interrupts
  asm volatile("int $0x3");
  asm volatile("int $0x2");

  // Initialize keyboard
  init_keyboard();
  // Initialize prompt
  init_prompt();
  
  /* Sleep 20 second
   * sleep(20); */

  return 0;
}