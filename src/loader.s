global loader
extern main

KERNEL_STACK_SIZE equ 4096

section .multiboot_header
header_start:
  dd 0xe85250d6                ; magic number
  dd 0                         ; protected mode code
  dd header_end - header_start ; header length

  ; checksum
  dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

  ; required end tag
  dw 0  ; type
  dw 0  ; flags
  dd 8  ; size
header_end:

section .text
loader:
  mov esp, kernel_stack + KERNEL_STACK_SIZE   ; set up stack pointer
  push ebx
  call main
.loop:
  jmp .loop

section .bss
align 4
kernel_stack:
  resb KERNEL_STACK_SIZE
