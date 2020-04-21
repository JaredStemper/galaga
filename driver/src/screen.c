/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c

*/
#include <f3d_lcd_sd.h>


void drawBackground(){
  f3d_fillScreen2(BLACK);
  //display level

  //display lives
  
}

void drawPlayer(struct player p){
  
}

//function to draw single enemy or array of enemies?
void drawEnemies(){
}

void drawBullet(int x, int y, uint16_t color){
  drawBar_vertical(x,y,y+3,color);
}
