/*
screen.c:
	Background (all black.. Add blues later), level (bottom right), lives at the bottom left, player ship, bullets, Enemies
Gets info for level, lives, player ship, and enemy ships from struct.c
*/



#include <screen.h>
#include <stdlib.h>



void drawStartScreen(void){
	f3d_lcd_fillScreen2(BLACK);
	f3d_lcd_drawString(45,70,  "GALAGA", RED,BLACK);
	f3d_lcd_drawString(25,90,"press any key", WHITE, BLACK);
	f3d_lcd_drawString(40,100, "to play", WHITE, BLACK);
} 

void drawEndLevelScreen(struct player *playerPtr){
	f3d_lcd_fillScreen2(BLACK);
		
		f3d_lcd_drawString(43,70,  "GOOOD JOB", GREEN,BLACK);
		f3d_lcd_drawString(23,90,"press r to", WHITE, BLACK);
		f3d_lcd_drawString(20,100, "play next level", WHITE, BLACK);	

} 
void drawEndScreen(struct player *playerPtr){
	f3d_lcd_fillScreen2(BLACK);
	if (playerPtr->life == 0) {
		f3d_lcd_drawString(43,70,  "BAD JOOOB", RED,BLACK);
		f3d_lcd_drawString(23,90,"press r to", WHITE, BLACK);
		f3d_lcd_drawString(35,100, "to play", WHITE, BLACK);
	}
	else {
		f3d_lcd_drawString(43,70,  "GOOOD JOB", GREEN,BLACK);
		f3d_lcd_drawString(23,90,"press r to", WHITE, BLACK);
		f3d_lcd_drawString(25,100, "to play again", WHITE, BLACK);	

	}
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

void drawPlayerStats(struct player *p) {
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

void eraseEnemyIndex(struct enemy e[], int enemyIndex){
	if (enemyIndex != 99999) { eraseEnemy(e[enemyIndex]); }
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
    int yshift = -3;
    int xshift = 3;

    if(liveBullets[i]){
      //if bullet is shot by player
      if(bArray[i].shooter==1){
	//if bullet is supposed to shoot straight
	if(bArray[i].angle == 2) { 
	  bArray[i].y1 = bArray[i].y1 + yshift;
	  bArray[i].y2 = bArray[i].y2 + yshift;    
	}
	//if bullet is supposed to shoot left diagonal
	else if(bArray[i].angle == 1) { 
	  bArray[i].y1 = bArray[i].y1 + yshift;
	  bArray[i].y2 = bArray[i].y2 + yshift;    
	  bArray[i].x1 = bArray[i].x1 - xshift;
	  bArray[i].x2 = bArray[i].x2 - xshift;    
	}
	//if bullet is supposed to shoot right diagonal
	else if(bArray[i].angle == 3) { 
	  bArray[i].y1 = bArray[i].y1 + yshift;
	  bArray[i].y2 = bArray[i].y2 + yshift;    
	  bArray[i].x1 = bArray[i].x1 + xshift;
	  bArray[i].x2 = bArray[i].x2 + xshift;    
	}
      }

      //if bullet is shot by enemy TODO: make bullet shoot towards player(at an angle)
      if(bArray[i].shooter==2){
	//if bullet is suppposed to shoot straight
	if(bArray[i].angle == 2) {
	  bArray[i].y1 = bArray[i].y1 - yshift;
	  bArray[i].y2 = bArray[i].y2 - yshift;
	}
	//if bullet is supposed to shoot left diagonal
	else if(bArray[i].angle == 1) {
	  bArray[i].y1 = bArray[i].y1 - yshift;
	  bArray[i].y2 = bArray[i].y2 - yshift;    
	  bArray[i].x1 = bArray[i].x1 - xshift;
	  bArray[i].x2 = bArray[i].x2 - xshift;
	}
	//if bullet is supposed to shoot right diagonal
	else if(bArray[i].angle == 3) {
	  bArray[i].y1 = bArray[i].y1 - yshift;
	  bArray[i].y2 = bArray[i].y2 - yshift;    
	  bArray[i].x1 = bArray[i].x1 + xshift;
	  bArray[i].x2 = bArray[i].x2 + xshift;  
	}
      }
    }
    /* 128x160 are board dimensions */
	//if bullet hits top or bottom of screen, mark as dead 
	if(bArray[i].y1 >= 160 || bArray[i].y1 <= 0) { liveBullets[i] = 0; }
	//if bullet hits left or right of screen, reverse movement
	if(bArray[i].x2 >= 128) { 
	  bArray[i].angle = 1;
	}
	else if(bArray[i].x1 <= 0) {
	  bArray[i].angle = 3;
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

int randShiftXList[] = {22, 28, -29, -26, 26, -25, 32, -35, -39, 21, -27, 35, 33, -33, 23, 27, 28, -38, 31, 36, 26, 40, -40, -27, 22, 31, 39, 32, -31, 20, -40, -32, -29, 27, 26, 37, 26, -39, -36, 23, 23, -40, 38, -34, -34, -25, -25, 20, 37, 36, 24, -34, -36, 34, -28, 20, -28, 36, -24, -20, -40, 34, -36, -33, -20, -34, -27, 34, 25, -21, -24, 28, -24, 24, -26, -33, 32, 23, 34, -33, 21, 33, 34, -29, -20, 31, -22, -38, -39, -30, 40, -21, -24, 21, 32, 20, -25, 36, 21, -36, -21, -40, -32, 26, 32, 35, 35, -23, -26, -36, 31, 39, 29, 26, -23, 37, 20, -32, -38, 34, 36, 31, 37, -40, -21, 21, -30, -20, -40, -30, 39, 26, 28, 36, -28, -31, 37, -38, -36, 32, -40, 25, 29, -25, 24, -20, -34, 29, 34, 22, -38, 23, -30, 31, -36, 26, -24, -27, 27, -37, 32, 39, -34, 36, 22, -40, -32, 34, 30, 23, -31, 26, -22, -33, -31, -25, -27, -26, -32, 21, -22, 37, 28, -35, 21, -26, 20, 22, 28, -24, -40, -34, 20, -30, 28, -24, -22, -37, 36, 36, 22, -25, 28, -36, -35, -33, 33, -36, 26, -30, 40, -20, 20, -33, 34, 32, 22, -23, 20, -33, -22, -39, 20, -26, 38, -36, -38, 20, -34, -23, 38, 23, -29, 37, 22, -35, 29, 23, -38, 30, -23, -31};


int randShiftYList[] = {-3,-5,-4,-1,-4,-1,-4,-4,-2,-3,-5,-4,-1,-3,-3,-3,-3,-2,-3,-3,-3,-2,-5,-2,-5,-4,-2,-5,-4,-3,-4,-4,-3,-5,-3,-5,-4,-1,-4,-2,-4,-1,-3,-3,-3,-2,-3,-5,-1,-4,-5,-5,-5,-3,-4,-4,-2,-4,-3,-5,-2,-3,-2,-5,-1,-2,-5,-3,-2,-5,-1,-3,-2,-3,-2,-3,-3,-3,-2,-5,-5,-2,-3,-3,-1,-5,-3,-5,-4,-5,-2,-5,-4,-1,-3,-5,-2,-3,-5,-3,-5,-5,-4,-2,-1,-2,-3,-4,-4,-5,-1,-3,-1,-3,-2,-5,-1,-1,-1,-5,-1};

/*
LevelOne:
	only move horizontally
LevelTwo:
	move downward, in diagonals quick enough to scare the player
*/

void moveEnemies(struct player *pPtr, struct enemy eArr[], int liveE[]){
  //shift currentX/currentY randomly, but take care not to go out of bounds
  for (int i=0; i<MAX_ENEMY; i++) {
    if(liveE[i]){
      int currentX = eArr[i].x1;
      int currentY = eArr[i].y1;				

      int shiftXby = randShiftXList[randomNumberGen(0,242)]; 	//uses first half of randList - should be -/+
      int finalX = currentX + shiftXby;

      //128x160 are official board dimensions. Check if LEFTMOST and RIGHTMOST values are within bounds x:0 and 128; y:0 and 160
      //since the furthest enemy from center is +-30, if that final result is not in bounds, reverse shift (may result in slight teleportation by edges...)
      if (finalX-30 < 0 || finalX+30 > 128) { finalX = currentX - shiftXby; } 
      //set new locations
      eArr[i].x1 = finalX;
      eArr[i].x2 = finalX + ENEMY_WIDTH;
    }
  }
}
void moveEnemiesTwo(struct player *pPtr, struct enemy eArr[], int liveE[]){
  //shift currentX/currentY randomly, but take care not to go out of bounds
  for (int i=0; i<MAX_ENEMY; i++) {
    if(liveE[i]){
      int currentX = eArr[i].x1;
      int currentY = eArr[i].y1;				

      int shiftXby = randShiftXList[randomNumberGen(0,242)]; 	//uses first half of randList - should be -/+
      int shiftYby = randShiftYList[randomNumberGen(0,121)];	//uses second half of randList - should be only -

      int finalX = currentX + shiftXby;
      int finalY = currentY - shiftYby;

      //128x160 are official board dimensions. Check if LEFTMOST and RIGHTMOST values are within bounds x:0 and 128; y:0 and 160
      //since the furthest enemy from center is +-30, if that final result is not in bounds, reverse shift (may result in slight teleportation by edges...)
      if (finalX-30 < 0 || finalX+30 > 128) { finalX = currentX - shiftXby; } 
      if (finalY-30 < 0)  { finalY = currentY - shiftYby; } 
      if (finalY > 160) { 
		liveE[i] = 0;
		--pPtr->lives;
		if (pPtr->lives <= 0) { pPtr->life = 0; }
	};
      //set new locations
      eArr[i].x1 = finalX;
      eArr[i].x2 = finalX + ENEMY_WIDTH;
		eArr[i].y1 = finalY;
		eArr[i].y2 = finalY + ENEMY_HEIGHT;
    }
  }
}

int randomNumberGen(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower ;
  return num;
}
/*
 * pseudo-randomly selects an enemy from the liveEnemies[] and makes a bullet near it
 * TODO: add to .h
*/
void enemyShoot(struct enemy eArray[], int liveEnemies[], struct player *p, struct bullet bArray[], int liveBullets[]){  
  int numOfShooters = randomNumberGen(1,7);

  for(int i=0; i<numOfShooters; i++){
    int shooter = randomNumberGen(0, MAX_ENEMY);

    if(liveEnemies[shooter]){
      makeEnemyBullet(eArray[shooter], bArray, liveBullets, p);
    }
  }
  

}

int textDisplayDelay = 20;
int playerDelay = 0;
int enemyShiftDelay = 5;

int enemyShootDelay = 5;

void drawAll(struct player *playerPtr, struct enemy e[], int liveEnemy[], struct bullet b[], int liveBullet[]) {
//	playerPtr->life = 0;
	if (textDisplayDelay == 0){ f3d_lcd_drawString(45,70,  "GALAGA", RED,BLACK); textDisplayDelay = 20; }

	drawPlayer(playerPtr);

	if (enemyShiftDelay == 0) { 
		eraseEnemies(e,liveEnemy);
		//check player level
		if (playerPtr->level == 1) {
			moveEnemies(playerPtr, e, liveEnemy); //higher the last parameter, the slower enemies move down
		}
		else {
			putchar('z');
			moveEnemiesTwo(playerPtr, e, liveEnemy); //higher the last parameter, the slower enemies move down
		}

		enemyShiftDelay = 5;
	}

	eraseBullets(b,liveBullet);
	if(enemyShootDelay==0){enemyShoot(e, liveEnemy, playerPtr, b, liveBullet); enemyShootDelay=40;}
	shoot(b,liveBullet);//probably should rename to moveBullets

	//check for collisions
	eraseEnemyIndex(e, checkCollision(playerPtr, liveBullet, b, liveEnemy, e)); //returns the index of the enemy that got hit
	drawBullets(b,liveBullet);
	drawEnemies(e,liveEnemy); 


	if (playerDelay == 10){ drawPlayerStats(playerPtr); playerDelay = 0; }

	playerDelay++;
	textDisplayDelay--;
	enemyShiftDelay--;
	enemyShootDelay--;

}

