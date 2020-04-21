/*
* main.c for lab 7
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper, Ray Lopez
*/

//#include <stdio.h>
//#include <stdlib.h>
#include <f3d_user_btn.h>
//#include <f3d_lcd_sd.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_i2c.h>
#include <f3d_delay.h>
#include <f3d_uart.h>
//#include <structs.h>
#include <screen.h>
//#include <helpers.h>

int main(){
  f3d_lcd_init();
  struct player p1;
  p1.level = 3;
  p1.score = 0;
  p1.lives = 3;
  p1.x1 = 63; p1.y1 = 130;
  p1.x1 = 67; p1.y2 = 140;

  struct enemy e1;
  e1.x1 = 63; e1.y1 = 30;
  e1.x2 = 67; e1.y2 = 40;

  
  //f3d_lcd_fillScreen2(BLACK);
  drawBackground(p1);
  drawPlayer(p1);
  drawEnemy(e1);
  drawBullet(65, 50, CYAN);
  
  
}


void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}
