#include "idt.h"
#include "../include/string.h"

extern void idt_flush(idt_ptr_t*);

idt_entry_t idt_entries[256]; //IDT contains 256 entries
idt_ptr_t   idt_ptr;

void init_idt() {
  idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
  idt_ptr.base = idt_entries;

  memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);

  idt_flush(&idt_ptr);
}
