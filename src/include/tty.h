#ifndef _TTY_H_
#define _TTY_H_

#define VGA_HEIGHT	80
#define VGA_WIDTH	25

struct term_struct{
  int col;
  int row;
};

void clear_screen();
void print(const char *string);
void put_char(char c);

#endif // _TTY_H_
