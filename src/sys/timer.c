#include "timer.h"
#include "isr.h"
#include "io.h"
#include "../include/tty.h"
#include "../include/string.h"

int timer_tick = 1000;
int limit = 0;

void timer(){
  char buf[3],*second;
  int temp = timer_tick/1000;

  if(temp < limit){
    second = itoa(temp, buf, 10);
    print_time(second);
  }
  timer_tick++;
}

void sleep_handler(uint32_t freq){
  /* The output from PIT channel 0 is connected to the PIC chip, 
   * so that it generates an "IRQ 0" */
  register_interrupt_handler(IRQ0, &timer);
  
  /* The oscillator used by the PIT chip runs at (roughly) 1.193182 MHz.
   * The basic principle of a frequency divider is
   * to divide one frequency to obtain a slower frequency */
  int div = 1193180/freq;

  // 0x43 : Mode/Command register (write only, a read is ignored)
  outb(0x43, 0x36);

  /* IRQ0 is generated by the rising edge of the Channel 0 output voltage 
   * (ie. the transition from "low" to "high", only). 
   * 0x40 : Channel 0 data port (read/write) */
  uint8_t low = (uint8_t)(div & 0xFF);
  uint8_t high = (uint8_t)((div>>8) & 0xFF);
  outb(0x40, low);
  outb(0x40, high);
}

void sleep(int second){
  limit = second + 1;
  sleep_handler(1000);
}