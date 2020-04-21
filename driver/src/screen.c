/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c

*/
#include <f3d_lcd_sd.h>



char level[10];
void drawBackground(struct player p){
  f3d_fillScreen2(BLACK);
  //display level
  sprintf(level, "Level: %d", p.level);
  f3d_lcd_drawString(120,154,level,WHITE,BLACK);
  //display lives
  
  f3d_lcd_drawString();
}

void drawPlayer(struct player p){
  
}

//function to draw single enemy or array of enemies?
void drawEnemies(){
}

void drawBullet(int x, int y, uint16_t color){
  drawBar_vertical(x,y,y+3,color);
}
