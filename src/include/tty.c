#include "int_types.h"
#include "tty.h"

// VGA text buffer is located at physical memory address 0xB8000.
volatile uint16_t* VGA_BUFFER = (uint16_t*)0xB8000;
const uint8_t WHITE_COLOUR = 0x0F;

struct term_struct *term_ptr,term_t;

void clear_screen(){
  uint16_t i=0;    
  /* VGA mode 3 provides a text interface 80 characters 
    wide and 25 characters lines per screen. */
  while(i < VGA_HEIGHT*VGA_WIDTH*2){
    VGA_BUFFER[i++] = 0;
  }

}

void term_init(){
  term_ptr = &term_t;

  for(int col = 0; col < VGA_HEIGHT; col++){
    for(int row = 0; row < VGA_WIDTH; row++){
      const size_t index = (VGA_HEIGHT * term_ptr->row) + term_ptr->col;
      // Set the character to blank
      VGA_BUFFER[index] = ((uint16_t)WHITE_COLOUR << 8) | ' ';
    }
  }

}
 
void put_char(char c){
  term_ptr = &term_t;

  switch (c){
    // new line character
    case '\n': {
      term_ptr->col = 0;
      term_ptr->row++;
      break;
    }
 
    default:{
      const size_t index = (VGA_HEIGHT * term_ptr->row) + term_ptr->col;
      VGA_BUFFER[index] = ((uint16_t)WHITE_COLOUR << 8) | c;
      term_ptr->col++;
      break;
    }
  }

  // New line
  if(term_ptr->col >= VGA_HEIGHT){
    term_ptr->col = 0;
    term_ptr->row++;
  }

  // Reset screen
  if(term_ptr->row >= VGA_WIDTH){
    term_ptr->col = 0;
    term_ptr->row = 0;
  }

}
 
void print(const char* string){
  for(size_t i=0; string[i] != '\0'; i++)
    put_char(string[i]);
}
