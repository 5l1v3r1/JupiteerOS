global gdt_flush      ; Allows the C code to call gdt_flush().

gdt_flush:
   mov eax,[esp + 4]  ; Fetch pointer to GDT and pass it as a parameter
   lgdt [eax]         ; Load the new GDT pointer

   mov ax,0x10        ; Data segment size 16 bytes.
                      ; So,it's offset is 0x10.
   
   mov ds,ax          ; Load all data segment registers
   mov es,ax
   mov fs,ax
   mov gs,ax
   mov ss,ax
   jmp 0x08:.flush    ; Each gdt entry is 8 bytes.So,it's offset is 0x08.
                      ; Do far jump

.flush:
   ret