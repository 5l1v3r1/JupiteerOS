OBJECTS = loader.o gdt_asm.o idt_asm.o

AS = nasm
ASFLAGS = -f elf

all: $(OBJECTS)
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
clean:
	rm -rf *.o
