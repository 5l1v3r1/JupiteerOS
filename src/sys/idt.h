#ifndef __IDT_H__
#define __IDT_H__

#include "../include/int_types.h"

/*Interrupt Descriptor Table tells the 
  CPU where to find handlers for each interrupt.*/

/* Highest 32 bits
|63       48| 47 |46 45| 44 |43     40|39  32|
|Offset high| P  | DPL | S  |Gate Type| Zero |*/

/* Lowest 32 bits
|31            16|15       0|
|Segment Selector|Offset Low|*/

struct idt_struct {
  uint16_t offset_low;
  uint16_t selector;
  uint8_t zero;
  unsigned gate_type:4;
  unsigned s:1;
  unsigned dpl:2;
  unsigned p:1;
  uint16_t offset_high;
} __attribute__((packed));
typedef struct idt_struct idt_entry_t;

struct idt_ptr {
  uint16_t limit;
  idt_entry_t *base;
} __attribute__((packed));
typedef struct idt_ptr idt_ptr_t;

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

void init_idt();

#endif // __IDT_H__
