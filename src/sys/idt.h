#ifndef __IDT_H__
#define __IDT_H__

#include "../include/int_types.h"

/* Highest 32 bits
|63       48| 47 |46 45| 44 |43     40|39  32|
|Offset high| P  | DPL | S  |Gate Type| Zero |*/

/* Lowest 32 bits
|31            16|15       0|
|Segment Selector|Offset Low|*/

struct idt_struct {
  uint16_t offset_low;
  uint16_t selector;
  unsigned zero:4;
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

void init_idt();

#endif // __IDT_H__
