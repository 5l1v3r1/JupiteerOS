#include "tty.h"
#include "int_types.h"

void clear_screen(){
    char *vga = (char*)VGA_BUFFER;
    uint16_t i=0;
    
    /* VGA mode 3 provides a text interface 80 characters 
    wide and 25 characters lines per screen. */   
    while( i < VGA_HEIGHT*VGA_WIDTH*2){
        vga[i++] = 0;
    }

}

void print(const char *string){
    char *vga = (char*)VGA_BUFFER;
    uint16_t i=0,j=0;

    /*Text mode memory takes two bytes for every "character" on screen. 
    One is the ASCII code byte, the other the attribute byte.*/    
    while (string[j] != '\0') {
        vga[i] = string[j++];
        vga[i+1] = WHITE_COLOUR;
        i += 2;
    }
}
