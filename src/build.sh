mkdir obj/
make -C asm
cp asm/*.o obj/
make -C sys
cp sys/*.o obj/
make -C include
cp include/*.o obj/
gcc -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c kernel_main.c -o obj/kernel_main.o
ld -melf_i386 -nostdlib -O2 -T link.ld -o kernel.elf obj/*.o
