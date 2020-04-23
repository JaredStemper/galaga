/*
* main.c for galaga
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper
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
  p1.x1 = 63+10; p1.y1 = PLAYER_Y1;
  p1.x2 = 67+10; p1.y2 = PLAYER_Y2;

  struct enemy e1;
  e1.x1 = 63; e1.y1 = 30;
  e1.x2 = 67; e1.y2 = 40;
  
  drawBackground(p1);
  drawPlayer(p1);
  drawEnemy(e1);
  drawBullet(63, 100, CYAN);
    
}


void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}
