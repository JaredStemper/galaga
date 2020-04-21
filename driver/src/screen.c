/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c

*/
#include <screen.h>


char level[10];
char lives[10];
char score[10];
void drawBackground(struct player p){
  f3d_lcd_fillScreen2(BLACK);

  //display level
  sprintf(level, "Level: %d", p.level);
  f3d_lcd_drawString(75,150,level,WHITE,BLACK);

  //display lives
  sprintf(level, "%d lives", p.lives);
  f3d_lcd_drawString(5,150,level,WHITE,BLACK);
  
  //score
  sprintf(level, "Score: %d", p.score);
  f3d_lcd_drawString(45,5,level,WHITE,BLACK);
 
// f3d_lcd_drawString();
}

void drawPlayer(struct player p){
  
}

//function to draw single enemy or array of enemies?
	//need a function to draw a single one, and then draw the array of them
void drawEnemy(struct enemy e){
}

//void drawEnemyArray();

void drawBullet(int x, int y, uint16_t color){
  drawBar_vertical(x,y,y+3,color);
}
