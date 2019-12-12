OBJECTS = loader.o kernel_main.o gdt_asm.o gdt.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

iso: kernel.elf
	cp kernel.elf iso/boot/
	grub-mkrescue iso -o JupiteerOS.iso

run: iso
	qemu-system-i386 -cdrom JupiteerOS.iso

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

bochs:
	bochs -f bochs.config -q 

clean:
	rm -rf *.o iso/boot/kernel.elf kernel.elf JupiteerOS.iso bochslog.txt
