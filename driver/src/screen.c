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
	f3d_lcd_drawString(45,70,  "GALAGA", RED,BLACK);
	f3d_lcd_drawString(30,90,"press SPACE", WHITE, BLACK);
	f3d_lcd_drawString(40,100, "to play", WHITE, BLACK);
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


void drawEnemy(struct enemy *e){
   drawRect(e->x1, e->y1, e->x2, e->y2, BLUE);
}

/*
e[] = { struct enemy e1,e2,e3}

liveenemy = {0,1,1,1,0,0,0,0}

enemyPosition= {{1,2}{2,3}{1,3}{2,1}{1,1}}
*/ 
//uses current list of enemy locations to determine the index of live enemies
void drawEnemies(struct enemy *e[], int liveEnemy[]){
  for (int i=0; i<30; i++) {
	if (liveEnemy[i]) {
		drawEnemy(e[i]);
	}
  }
}



void drawBullet(struct bullet *b){
   drawRect(b->x1, b->y1, b->x2, b->y2, CYAN);
}



void drawBullets(struct bullet *b[], int liveBullet[]){



}

/*
 * makes a bullet at player position
 * decrements y position of the bullet (bullet goes up straight)
 * TODO: add same functionality for enemy
*/
//void shoot(){

//}

//void movePlayer(){
//}

//after collision, bullet array marks bullet index as 0

void drawAll(struct player *playerPtr, struct enemy *e[], int liveEnemy[], struct bullet *b[], int liveBullet[]) {
	drawBackground(playerPtr);
	drawPlayer(playerPtr);
	drawEnemies(e,liveEnemy);
	drawBullets(b,liveBullet);
}
