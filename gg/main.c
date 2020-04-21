/*
* main.c for lab 7
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper, Ray Lopez
*/

//#include <stdio.h>
//#include <stdlib.h>
#include <f3d_user_btn.h>
#include <f3d_lcd_sd.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_i2c.h>
#include <f3d_delay.h>
#include <f3d_uart.h>
#include <screen.h>
#include <helpers.h>
#include <structs.h>

int main(){
  f3d_lcd_init();
  struct player p1;
  p1.level = 3;

  drawBackground(p1);
  
  
}


void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}
