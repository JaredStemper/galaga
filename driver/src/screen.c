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
  for(int i=0; i<MAX_BULLET; i++){
    if(liveBullet[i]){
      drawBullet(b[i]);
    }
  }
}

/*
 * makes ONE bullet at player position and adds it to bulletArray(which is globally defined)
 * TODO: add same functionality for enemy
 * TODO: add to .h file
*/
void makeBullet(struct player *playerPtr, struct bullet *bulletArray[], int liveBullets[]){
  int x = (playerPtr->x1 / playerPtr->x2)/2;
  int y = playerPtr->y1;

  struct bullet *bulletPointer;
  bulletPointer->x1 = x;
  bulletPointer->x2 = x+BULLET_WIDTH;
  bulletPointer->y1 = y;
  bulletPointer->y2 = y+BULLET_HEIGHT;
  bulletPointer->color = 0xFFFF;
  bulletPointer->shooter = 1;

  for(int j=0; j<BULLET_MAX, j++){
    if(!liveBullets[j]){
      liveBullets[j] = 1;
      bulletArray[j] = &bulletPointer;
      break;
    } else{j++;}
  }  
  
}
/*
 * TODO: add to .h file
 * TODO: add attribute alive to struct bullet
 */
void shoot(struct bullet *bulletPointer){
  while(bulletPointer->y1 < 0 || bulletPointer->alive = 0){
    bulletPointer->y1 = bulletPointer->y1 - 3;
    bulletPointer->y2 = bulletPointer->y2 - 3;
    //delay(1000); //should we do this? // need to have the bullet go up little by little
  }  
}

//void movePlayer(){
//}

//after collision, bullet array marks bullet index as 0

void drawAll(struct player *playerPtr, struct enemy *e[], int liveEnemy[], struct bullet *b[], int liveBullet[]) {
	drawBackground(playerPtr);
	drawPlayer(playerPtr);
	drawEnemies(e,liveEnemy);
	drawBullets(b,liveBullet);
}
