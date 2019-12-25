#include "include/int_types.h"
#include "sys/gdt.h"
#include "sys/idt.h"
#include "include/tty.h"

int main(){
    clear_screen();
    init_gdt();
    init_idt();
    print("Welcome to JupiteerKernel!");
    return 0;
}
