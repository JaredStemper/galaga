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
 
}

void drawPlayer(struct player p){
  drawRect(p.x1, p.y1, p.y2, p.x2, RED);
}

//function to draw single enemy or array of enemies?
	//need a function to draw a single one, and then draw the array of them
void drawEnemy(struct enemy e){
   drawRect(e.x1, e.y1, e.y2, e.x2, BLUE);
}

void drawEnemies(struct enemy e[]){
  int l = sizeof e/sizeof e[0];
  int i;
  for(i=0;i<l;i++){
     drawRect(e[i].x1, e[i].y1, e[i].y2, e[i].x2, BLUE);
  }
}

void drawBullet(int x, int y, uint16_t color){
  drawRect(x,y,y+3,x+2,color);
}
