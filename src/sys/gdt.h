#include "../include/int_types.h"

/* GDT contains entries that provide information to the CPU about memory segments.
GRUB sets a GDT up for operating system. But we don't know where that GDT is, or what's in it. 
So we could accidentally overwrite it, then computer would triple-fault and reset.
Such a bad situation... :) */

#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

void init_gdt();

/*
   GDT Entry
   ---------------------------------------------------------------
   |31                              16|15                       0|
   ---------------------------------------------------------------
   |            Base 0:15             |       Limit 0:15         |
   ---------------------------------------------------------------
   |63        50|55   52|51         48|47         40|39        32|
   ---------------------------------------------------------------
   | Base 24:31 | Flags | Limit 16:19 | Access Byte | Base 16:23 |
   ---------------------------------------------------------------
*/

struct gdt_entry_struct{
   uint16_t limit_low;
   uint16_t base_low;     
   uint8_t  base_middle;
   uint8_t  access_byte;  
   unsigned limit_high: 4;
   unsigned flags: 4;
   uint8_t  base_high;     
} __attribute__((packed));  // 'packed' to tell GCC not to change any of the alignment in the structure.
typedef struct gdt_entry_struct gdt_entry_t; 

struct gdt_ptr_struct{
    uint16_t limit;       // The upper 16 bits of all selector limits.
    uint32_t base;        // The address of the first gdt_entry_t struct.
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

#endif  // INCLUDE_GDT_H
