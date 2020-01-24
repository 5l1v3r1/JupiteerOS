#include "int_types.h"
#include "tty.h"
#include "../sys/io.h"
#include "string.h"

// VGA text buffer is located at physical memory address 0xB8000.
volatile uint16_t* VGA_BUFFER = (uint16_t*)0xB8000;
const uint8_t WHITE_COLOUR = 0x0F;

struct term_struct *term_ptr,term_t;

void reset_screen(){
  term_ptr->col = 0;
  term_ptr->row = 0;
}

void clear_screen(){
  uint16_t i=0;    
  /* VGA mode 3 provides a text interface 80 characters 
  wide and 25 characters lines per screen. */
  while(i < VGA_HEIGHT*VGA_WIDTH*2){
    VGA_BUFFER[i++] = 0;
  }
  reset_screen();
}


void new_line(){
  if(term_ptr->row >= VGA_WIDTH){
    reset_screen();
    clear_screen();
  }
  term_ptr->col = 0;
  term_ptr->row++;
}

void print_char(char c,uint8_t col){
  // New line character
  if (c == '\n'){
    new_line();
  }
  else{
    size_t index = (VGA_HEIGHT * term_ptr->row) + term_ptr->col;
    VGA_BUFFER[index] = ((uint16_t)col << 8) | c;
    term_ptr->col++;
  }
}
 
void print(const char* str){
  for(size_t i=0; str[i] != '\0'; i++)
    print_char(str[i],WHITE_COL);
}

void color_print(const char* str,uint8_t col){
  for(size_t i=0; str[i] != '\0'; i++)
    print_char(str[i],col);
}

void back_space(){
  term_ptr->col = term_ptr->col - 1;
  size_t index = (VGA_HEIGHT * term_ptr->row) + term_ptr->col;
  VGA_BUFFER[index] = ((uint16_t)WHITE_COL << 8) | ' ';
}

void init_prompt(){
  new_line();
  color_print("jupiteer@jupiteer ",GREEN_COL);
}

void print_time(char* sec){
  reset_screen();

  for(int i = 0; i < strlen(sec); ++i){
    size_t index = (VGA_HEIGHT * term_ptr->row) + term_ptr->col;
    VGA_BUFFER[index] = ((uint16_t)WHITE_COL << 8) | sec[i];  
    term_ptr->col++;
  }

}