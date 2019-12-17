iso: kernel.elf
	cp kernel.elf iso/boot/
	grub-mkrescue iso -o JupiteerOS.iso

run: iso
	qemu-system-i386 -cdrom JupiteerOS.iso

bochs:
	bochs -f bochs.config -q 

clean:
	rm -rf *.o iso/boot/kernel.elf kernel.elf \
		JupiteerOS.iso bochslog.txt sys/*.o asm/*.o obj/

