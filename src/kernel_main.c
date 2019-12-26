#include "include/int_types.h"
#include "include/tty.h"
#include "sys/gdt.h"
#include "sys/idt.h"

int main(){
    clear_screen();
    init_gdt();
    init_idt();

    print("Welcome to JupiteerKernel!");

    // Interrupts
    asm volatile ("int $0x3");
    asm volatile ("int $0x2");

    return 0;
}
