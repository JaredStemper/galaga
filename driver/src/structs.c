/*
  Aliens
  Only bottom row aliens shoot (randomly?)
  color

  Bullets
  Thin vertical line, if x and y dimensions of the line intersect with any part of the area of the line, it will destroy what it hits
  Moves in a motion of 3 angles. straight, angled left, angled right. 
  should angle towards player 

  Player
  color, Lives left, level, player score
*/

#include <structs.h>
#include <f3d_uart.h>


/*//// Collisions ////*/


//should this function be void? or is there another check that needs to be done afterwards -> doing this because it makes testing easier


/*
  blife and elife arr
  .life for enemies
*/
int checkCollision(struct player *p, int blifeArr[], struct bullet bArr[], int elifeArr[], struct enemy eArr[]) {
  //check for every live bullet
  for (int i=0; i<MAX_BULLET; i++) {
    if (blifeArr[i]) {
      struct bullet b = bArr[i];
			
      //if bullet comes from enemy and hits player
      if (b.shooter == 2) {
	if (ifCollision(b.x1,b.x2, b.y1,b.y2, p->x1,p->x2, p->y1,p->y2)) { 
	  --p->lives; //lives start at 3, decrements until "dead"
	  blifeArr[i] = 0;
	  if (p->lives <= 0) {
	    p->life = 0;
	  }
	  return 99999; //true, there was a collision
	}
      }

      //if bullet comes from player and hits enemy
      if(b.shooter == 1){
	//check every live enemy
	for (int j=0; j<MAX_ENEMY; j++) {
	  struct enemy e = eArr[j];
	  //if enemy is alive
	  if (elifeArr[j]) {
	    //if collision, set life to 0 and return 1 (for true)
	    if (ifCollision(b.x1,b.x2, b.y1,b.y2, e.x1,e.x2, e.y1, e.y2)) { //TODO: always returns true
	      elifeArr[j] = 0;
	      blifeArr[i] = 0;
	      e.life = 0; //deprecated?
	      p->score = p->score+5;
	      enemyCounter--;
	      return j; //returns index of enemy that got hit - for erasing in screen.c
	    }
	  }
	}
      }
    }
  }
  return 0; //false, no collision
}

int ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2) {
  int collision = 0;
  //if tl
  if(pointInRectangle(bx1, by1, x1, x2, y1, y2)) {
	collision = 1;
  }
  //if tr
 if (pointInRectangle(bx2, by1, x1, x2, y1, y2)) {
	collision = 1;
  }
  //if bl
 if (pointInRectangle(bx1, by2, x1, x2, y1, y2)) {
	collision = 1;
  }
  //if br
  if (pointInRectangle(bx2, by2, x1, x2, y1, y2)) {
	collision = 1;
  }
  //if rectangle is not in rectangle
  return collision; // default no collision
}

int pointInRectangle(int x, int y, int x1, int x2, int y1, int y2) {
  if (x >= x1 && x <= x2){
	if ( y >= y1 && y <= y2) {
		    return 1; 
	}
  }

  return 0;
}

/*
  tl=(x1,y1)   tr=(x2,y1)
  _____
  |   | 
  |   | 
  ----- 
  bl=(x1,y2)   br=(x2,y2)
*/


/*
  struct enemy = e1;
  struct enemy = e2;

  struct enemy* e1Ptr = &e1;
  struct enemy* e2Ptr = &e2;

  struct enemy *enemyArray[] = (struct enemy*) malloc(30);

  makeEnemies(2, enemyArray);

  int arr[] = [1,2,3]

  arr[2] = MAX_INT;


  Input:  int of enemies to add to enemyArray,
  arrayPointer containing enemyStructPointers

  runs a loop of "numOfEnemies" amount to add a new enemy to the enemyArray

*/

int enemyPositions[30][2] = {
  {CENTERX,CENTERY}, {CENTERX-10,CENTERY+10}, {CENTERX+10,CENTERY-10}, {CENTERX-10,CENTERY-10}, {CENTERX+10,CENTERY+10},
  {CENTERX-20,CENTERY+20}, {CENTERX+20,CENTERY-20}, {CENTERX-20,CENTERY-20}, {CENTERX+20,CENTERY+20},

  {CENTERX,CENTERY+10}, {CENTERX-10,CENTERY+20}, {CENTERX-10,CENTERY-20}, {CENTERX+10,CENTERY-20}, {CENTERX+10,CENTERY+20},
  {CENTERX,CENTERY-10}, {CENTERX-20,CENTERY+10}, {CENTERX-20,CENTERY-10}, {CENTERX+20,CENTERY-10}, {CENTERX+20,CENTERY+10},

  {CENTERX-10,CENTERY}, {CENTERX,CENTERY+20}, {CENTERX,CENTERY-20}, {CENTERX-20,CENTERY}, {CENTERX+20,CENTERY},
  {CENTERX+10,CENTERY}, {CENTERX,CENTERY+30}, {CENTERX-30,CENTERY}, {CENTERX,CENTERY+30}, {CENTERX,CENTERY-30},

  {CENTERX+10,CENTERY+30}
};

void makeEnemies(int numOfEnemies, struct enemy eArray[], int locationArray[]) {
  int i = 0; //keeps track of enemies that have been successfully made		

  struct enemy defaultEnemy;

  //find location in arrayLiveEnemies that is empty/dead, and place enemy
  for (int j = 0; j < MAX_ENEMY; j++) { 
    //if enemy is dead, make new enemy
    if(!locationArray[j]) {
      i++;	
      //update locationArray
      locationArray[j] = 1;

      //create enemy and ptr to it
      eArray[j] = defaultEnemy;

      //set location for new enemy using reference to struct object 
      eArray[j].locationIndex = j;
	
  
      eArray[j].x1 = enemyPositions[j][0];
      eArray[j].x2 = eArray[j].x1 + ENEMY_WIDTH;
      eArray[j].y1 = enemyPositions[j][1];
      eArray[j].y2 = eArray[j].y1 + ENEMY_HEIGHT;

      eArray[j].life = 1;
      eArray[j].color = 0x001F;

    }
    else if(j == MAX_ENEMY-1) {
      // printf("Went over max_enemy amount");
      break; 
    }

    if(i == numOfEnemies) { break; } //after iterating numOfEnemies times, break

		
  }

} 

/*
 * makes ONE bullet at player position and adds it to bulletArray(which is globally defined)
 */
void makeBullet(struct player *playerPtr, struct bullet bArray[], int liveBullets[]){
  int x = (playerPtr->x1 + playerPtr->x2)/2;
  int y = playerPtr->y1;
  float mag_data[3];
  int heading;

  struct bullet b1;
  b1.x1 = x;
  b1.x2 = x+BULLET_WIDTH;
  b1.y1 = y;
  b1.y2 = b1.y1+BULLET_HEIGHT;
  b1.color = 0xFFFF;
  b1.shooter = 1; //needs to check if enemy or player before shooting/setting location
  b1.angle = 2; //default bullet shoots straight

  for(int j=0; j<MAX_BULLET; j++){
    if(!liveBullets[j]){
      liveBullets[j] = 1;
      bArray[j] = b1;

      //check heading to set bullet angle
      f3d_mag_read(mag_data); //magxs
      heading = get_heading(mag_data);
      bArray[j].angle = bulletAngle(heading, playerPtr->starterHeading); 
      break;
    } else{j++;} //ask Jared if he put this here or if I (kp) did?
  }

}
//TODO: add to .h
void makeEnemyBullet(struct enemy e, struct bullet bArray[], int liveBullets[], struct player *p){
  int x = (e.x1 + e.x2)/2;
  int y = e.y1;

  struct bullet b1;
  b1.x1 = x;
  b1.x2 = x+BULLET_WIDTH;
  b1.y1 = y+ENEMY_HEIGHT;
  b1.y2 = b1.y1+BULLET_HEIGHT;
  b1.color = 0x07E0;
  b1.shooter = 2; //needs to check if enemy or player before shooting/setting location
  b1.angle = 2; //default bullet shoots straight

  for(int j=0; j<MAX_BULLET; j++){
    if(!liveBullets[j]){
      liveBullets[j] = 1;
      bArray[j] = b1;

      //calculate bullet angle using player position and enemy position
      //initial thought: if player is left of enemy, shoot towards left
      if(p->x1 == e.x1){
	bArray[j].angle = 2;
      }
      if(p->x1 < e.x1+20 || p->x1 > e.x1-20 ){
	bArray[j].angle = 2;
      }
      if(p->x1 < e.x1-20){
	bArray[j].angle = 1;
      }
      if(p->x1 > e.x1+20){
	bArray[j].angle = 3;
      }

      
      break;
    } else{j++;} 
  }
  
  
}
