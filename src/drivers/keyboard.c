#include <drivers/keyboard.h>
#include <drivers/us_keyboard_map.h>
#include <kernel/tty.h>
#include <libc/stdint.h>
#include <sys/io.h>
#include <sys/isr.h>

extern uint8_t us_keyboard_map[128];
int cmd_index = 0;

void keyboard_handler() {
  uint8_t status;
  char scan_code;

  // 0x64: Keyboard status port
  status = inb(0x64);

  // Check the data, is it empty?
  if (status & 0x01) {
    // 0x60 : Keyboard data port
    scan_code = inb(0x60);

    if (scan_code < 0) {
      return;
    }

    // Backspace Key
    if (scan_code == 0x0E) {
      if (cmd_index <= 0) {
        // if we're at the first character of the command
        // then avoid backspace to not to delete prompt.
        return;
      }
      cmd_index--;
      back_space();
      return;
    }

    // 0x1C : Enter Key
    if (scan_code == 0x1C) {
      init_prompt();
      cmd_index = 0;
      return;
    }
    print_char(us_keyboard_map[(uint8_t)scan_code]);
    cmd_index += 1;
  }
}

void init_keyboard() { 
  register_interrupt_handler(IRQ1, &keyboard_handler); 
}