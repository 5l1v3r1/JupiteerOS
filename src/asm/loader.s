global loader
extern main

KERNEL_STACK_SIZE equ 4096

section .text
loader:
  ; set up stack pointer
  mov esp, kernel_stack + KERNEL_STACK_SIZE
  push ebx
  call main
.loop:
  jmp .loop

section .bss
align 4
kernel_stack:
  ; resb, declare uninitialized storage space. 
  resb KERNEL_STACK_SIZE