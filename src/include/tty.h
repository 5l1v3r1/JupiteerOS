#ifndef _TTY_H_
#define _TTY_H_
#include "../include/int_types.h"

#define VGA_HEIGHT	80
#define VGA_WIDTH	  25

struct term_struct{
  int col;
  int row;
};

void clear_screen();
void print(const char *string);
void print_char(char c,uint8_t col);
void init_prompt();
void back_space();

#define BLACK_COL         0
#define BLUE_COL          1
#define GREEN_COL         2
#define CYAN_COL          3
#define RED_COL           4
#define MAGENTA_COL       5
#define BROWN_COL         6
#define LIGHT_GREY_COL    7
#define DARK_GREY_COL     8
#define LIGHT_BLUE_COL    9
#define LIGHT_GREEN_COL   10
#define LIGHT_CYAN_COL    11
#define LIGHT_RED_COL     12
#define LIGHT_MAGENTA_COL 13
#define LIGHT_BROWN_COL   14
#define WHITE_COL    	    15

#endif // _TTY_H_