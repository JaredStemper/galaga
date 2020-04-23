/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c


*/
#include <screen.h>

/*
}
move arrayenemies {
        randomMovement(-5,5); //as long as the center is not so far left or so far right
        CENTERX = CENTERX+2;
        CENTERY = CENTERY-2;
}


|   -    -   -
|     -    -  
|        -
|
|
--------------
*/




void drawStartScreen(void){
	f3d_lcd_fillScreen2(BLACK);
	f3d_lcd_drawString(60,70, "GALAGA", RED,BLACK);
	f3d_lcd_drawString(60,90,"press SPACE to play", WHITE, BLACK);
} 



char level[10];
char lives[10];
char score[10];

void drawBackground(struct player *p){
  f3d_lcd_fillScreen2(BLACK);

  //display level
  sprintf(level, "Level: %d", p->level);
  f3d_lcd_drawString(75,150,level,WHITE,BLACK);

  //display lives
  sprintf(level, "%d lives", p->lives);
  f3d_lcd_drawString(5,150,level,WHITE,BLACK);
  
  //score
  sprintf(level, "Score: %d", p->score);
  f3d_lcd_drawString(45,5,level,WHITE,BLACK);
 
}

void drawPlayer(struct player *p){
  drawRect(p->x1, p->y1, p->x2, p->y2, RED);
}

//function to draw single enemy or array of enemies?
	//need a function to draw a single one, and then draw the array of them
void drawEnemy(struct enemy *e){
   drawRect(e->x1, e->y1, e->x2, e->y2, BLUE);
}


void drawEnemies(struct enemy *e[]){
  int l = (int) sizeof(e)/sizeof(e[0]);  //TODO fix this line
  int i;
  for(i=0;i<l;i++){
     drawEnemy(e[i]);  //drawRect(e[i].x1, e[i].y1, e[i].x2, e[i].y2, BLUE);
  }
}

void drawBullet(struct bullet *b){
   drawRect(b->x1, b->y1, b->x2, b->y2, CYAN);
}
