/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c
*/



#include <screen.h>




void drawStartScreen(void){
	f3d_lcd_fillScreen2(BLACK);
	f3d_lcd_drawString(45,70,  "GALAGA", RED,BLACK);
	f3d_lcd_drawString(25,90,"press any key", WHITE, BLACK);
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
void erasePlayer(struct player *p){
  drawRect(p->x1, p->y1, p->x2, p->y2, BLACK);
}


void drawEnemy(struct enemy e){
   drawRect(e.x1, e.y1, e.x2, e.y2, BLUE);
}
void eraseEnemy(struct enemy e){
   drawRect(e.x1, e.y1, e.x2, e.y2, BLACK);
}

/*
e[] = { struct enemy e1,e2,e3}

liveenemy = {0,1,1,1,0,0,0,0}

enemyPosition= {{1,2}{2,3}{1,3}{2,1}{1,1}}
*/ 
//uses current list of enemy locations to determine the index of live enemies
void drawEnemies(struct enemy e[], int liveEnemy[]){
  for (int i=0; i<30; i++) {
	if (liveEnemy[i]) {
		drawEnemy(e[i]);
	}
  }
}
void eraseEnemies(struct enemy e[], int liveEnemy[]){
  for (int i=0; i<30; i++) {
	if (liveEnemy[i]) {
		eraseEnemy(e[i]);
	}
  }
}



void drawBullet(struct bullet *b){
   drawRect(b->x1, b->y1, b->x2, b->y2, CYAN);
}
void eraseBullet(struct bullet *b){
   drawRect(b->x1, b->y1, b->x2, b->y2, BLACK);
}



void drawBullets(struct bullet b[], int liveBullet[]){
  for(int i=0; i<MAX_BULLET; i++){
    if(liveBullet[i]){
      drawBullet(&b[i]);
    }
  }
}
void eraseBullets(struct bullet b[], int liveBullet[]){
  for(int i=0; i<MAX_BULLET; i++){
    if(liveBullet[i]){
      eraseBullet(&b[i]);
    }
  }
}

void shoot(struct bullet bArray[], int liveBullets[]){
  //if bullet in liveBullets leaves the screen, mark as dead
  for(int i=0; i < MAX_BULLET; i++){
    if(liveBullets[i]){
     bArray[i].y1 = bArray[i].y1-3;
     bArray[i].y2 = bArray[i].y2-3;    
	//if bullet hits top or bottom of screen, mark as dead
	if(bArray[i].y1 >= 160 || bArray[i].y1 <= 0) { liveBullets[i] = 0; }
    }
  }  
}

void movePlayer(struct player *p, int input){
  switch(input){
  case 'a':
  case 'A':
    if(p->x1 > 10){
      p->x1 = p->x1 - 10;
      p->x2 = p->x2 - 10;
    }
    else {
      p->x1 = 0;
      p->x2 = 4;
    }
    break;
  case 'd':
  case 'D' :
    if(p->x2 < 127){
      p->x1 = p->x1 + 10;
      p->x2 = p->x2 + 10;
    }
    else {
      p->x1 = 123;
      p->x2 = 127;
    }

    
    break;
  }
}

int randShiftList[] = {22, 28, -29, -26, 26, -25, 32, -35, -39, 21, -27, 35, 33, -33, 23, 27, 28, -38, 31, 36, 26, 40, -40, -27, 22, 31, 39, 32, -31, 20, -40, -32, -29, 27, 26, 37, 26, -39, -36, 23, 23, -40, 38, -34, -34, -25, -25, 20, 37, 36, 24, -34, -36, 34, -28, 20, -28, 36, -24, -20, -40, 34, -36, -33, -20, -34, -27, 34, 25, -21, -24, 28, -24, 24, -26, -33, 32, 23, 34, -33, 21, 33, 34, -29, -20, 31, -22, -38, -39, -30, 40, -21, -24, 21, 32, 20, -25, 36, 21, -36, -21, -40, -32, 26, 32, 35, 35, -23, -26, -36, 31, 39, 29, 26, -23, 37, 20, -32, -38, 34, 36, 31, 37, -40, -21, 21, -30, -20, -40, -30, 39, 26, 28, 36, -28, -31, 37, -38, -36, 32, -40, 25, 29, -25, 24, -20, -34, 29, 34, 22, -38, 23, -30, 31, -36, 26, -24, -27, 27, -37, 32, 39, -34, 36, 22, -40, -32, 34, 30, 23, -31, 26, -22, -33, -31, -25, -27, -26, -32, 21, -22, 37, 28, -35, 21, -26, 20, 22, 28, -24, -40, -34, 20, -30, 28, -24, -22, -37, 36, 36, 22, -25, 28, -36, -35, -33, 33, -36, 26, -30, 40, -20, 20, -33, 34, 32, 22, -23, 20, -33, -22, -39, 20, -26, 38, -36, -38, 20, -34, -23, 38, 23, -29, 37, 22, -35, 29, 23, -38, 30, -23, -31};




void moveEnemies(struct player *pPtr){
	//shift CENTERX/CENTERY randomly, but take care not to go out of bounds

	int shiftXby = randShiftList[CENTERY * pPtr->x2 % 121]; 	//uses second half of randList
	int shiftYby = randShiftList[122 + CENTERX * pPtr->x1 % 242];	//uses first half of randList

        putIntString(shiftXby);

/*
	int finalX = CENTERX + shiftXby;
	int finalY = CENTERY + shiftYby;

	//128x160 are official board dimesnions. Check if LEFTMOST and RIGHTMOST values are within bounds x:0 and 128; y:0 and 160
	//since the furthest enemy from center is +-30, if that final result is not in bounds, reverse shift (may result in slight teleportation by edges...)
	if (finalX-30 < 0 || finalX+30 > 128) { finalX = CENTERX - shiftXby; } 
	if (finalY-30 < 0 || finalY+30 > 160) { finalX = CENTERX - shiftXby; } 

	#define CENTERX finalX
	#define CENTERY finalY
*/	
}

//after collision, bullet array marks bullet index as 0


int textDisplayDelay = 5;
int enemyShiftDelay = 95;


void drawAll(struct player *playerPtr, struct enemy e[], int liveEnemy[], struct bullet b[], int liveBullet[]) {

	if (textDisplayDelay == 0){ f3d_lcd_drawString(45,70,  "GALAGA", RED,BLACK); textDisplayDelay = 5; }

	drawPlayer(playerPtr);

	if (enemyShiftDelay == 0) { 
		eraseEnemies(e,liveEnemy);








/*
		int a = 69;
		int atemp = a;
		int btemp = a;
		int count;
		while(atemp) { atemp /= 10; count++; }
		char strArr[count+1];
		for (int b=0; b<count; b++) {
			strArr[b] = btemp % 10;
			btemp /= 10;
			putchar(b + '0');
		}
		putchar('z');
		strArr[count+1] = '\0';
		//char aa[] = {'6','9','\0'};
*/
         










		moveEnemies(playerPtr);//bases enemy movements partially on player location, to add to randomness of movement 
		drawEnemies(e,liveEnemy); 
		enemyShiftDelay = 95;
	}

	eraseBullets(b,liveBullet);
	shoot(b,liveBullet);
	drawBullets(b,liveBullet);

	textDisplayDelay--;
	enemyShiftDelay--;
}
