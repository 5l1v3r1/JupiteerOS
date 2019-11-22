#define WHITE_COLOUR 0x7
#define VGA_HEIGHT 80
#define VGA_WIDTH 25
// VGA text buffer is located at physical memory address 0xB8000.
#define VGA_BUFFER 0xb8000

void clear_screen(){
    char *vga = (char*)VGA_BUFFER;
    int i=0;
    
    /* VGA mode 3 provides a text interface 80 characters 
    wide and 25 characters lines per screen. */   
    while( i < VGA_HEIGHT*VGA_WIDTH*2){
        vga[i++] = 0;
    }

}

void print(const char *string){
    char *vga = (char*)VGA_BUFFER;
    int i=0,j=0;

    /*Text mode memory takes two bytes for every "character" on screen. 
    One is the ASCII code byte, the other the attribute byte.*/    
    while (string[j] != '\0') {
        vga[i] = string[j++];
        vga[i+1] = WHITE_COLOUR;
        i += 2;
    }
}

int main(){
    clear_screen();
    print("Welcome to JupiteerKernel!");
    return 0;
}
