OBJECTS = gdt.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
all:$(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@
clean:
	rm -rf *.o 
