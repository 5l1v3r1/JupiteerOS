extern isr_handler

%macro ISR_NOERRCODE 1
global isr%1
isr%1:
  cli                   ; clear interrupts
  push byte 0           ; push dummy error code
  push byte %1          ; push the interrupt number
  jmp isr_common_stub   ; jump to common handler
%endmacro

%macro ISR_ERRCODE 1
global isr%1
isr%1:
  cli                   ; clear interrupts
  push byte %1          ; push the interrupt number
  jmp isr_common_stub   ; jump to common handler
%endmacro

isr_common_stub:
  pusha                 ; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax
  mov ax, ds            ; Lower 16-bits of eax = ds.
  push eax              ; save the data segment descriptor
  mov ax, 0x10          ; load the kernel data segment descriptor
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  call isr_handler
  pop eax               ; reload the original data segment descriptor
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  popa                  ; Pops edi,esi,ebp,esp,ebx,edx,ecx,eax
  add esp, 8            ; Cleans up the pushed error code and pushed ISR number
  sti                   ; re-enable hardware interrupts
  iret                  ; pops CS, EIP, EFLAGS, SS, and ESP

ISR_NOERRCODE 0
ISR_NOERRCODE 1
ISR_NOERRCODE 2
ISR_NOERRCODE 3
ISR_NOERRCODE 4
ISR_NOERRCODE 5
ISR_NOERRCODE 6
ISR_NOERRCODE 7
ISR_ERRCODE   8
ISR_NOERRCODE 9
ISR_ERRCODE   10
ISR_ERRCODE   11
ISR_ERRCODE   12
ISR_ERRCODE   13
ISR_ERRCODE   14
ISR_NOERRCODE 15
ISR_NOERRCODE 16
ISR_ERRCODE   17
ISR_NOERRCODE 18
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31