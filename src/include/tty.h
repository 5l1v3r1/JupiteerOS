#ifndef _TTY_H_
#define _TTY_H_

#define WHITE_COLOUR 0x7
#define VGA_HEIGHT   80
#define VGA_WIDTH    25
// VGA text buffer is located at physical memory address 0xB8000.
#define VGA_BUFFER   0xb8000

void clear_screen();
void print(const char *string);

#endif // _TTY_H_
