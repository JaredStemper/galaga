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

/*//// Collisions ////*/


//should this function be void? or is there another check that needs to be done afterwards -> doing this because it makes testing easier
int checkEnemyCollision(struct bullet *b, struct enemy *e) {
  //if collision, set life to 0 and return 1 (for true)
  if (ifCollision(b->x1,b->x2, b->y1,b->y2, e->x1,e->x2, e->y1,e->y2, e->life)) { 
    usedEnemyPositions[e->locationIndex] = 0;
    e->life = 0;
    return 1; //true, there was a collision
  }
  return 0; //false, no collision
}

//checks coordinates, struct type
int checkPlayerCollision(struct bullet *b, struct player *p) {
  if (ifCollision(b->x1,b->x2, b->y1,b->y2, p->x1,p->x2, p->y1,p->y2, p->life)) { 
    --p->lives;
    if (p->lives <= 0) {
      p->life = 0;
    }
    return 1; //true, there was a collision
  }
  return 0; //false, no collision
}

int ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, int life) {


  //if life is false, don't check
  if(!life) { return 0; }
  //if tl
  else if(pointInRectangle(bx1, by1, x1, x2, y1, y2)) {
    return 1;
  }
  //if tr
  else if (pointInRectangle(bx2, by1, x1, x2, y1, y2)) {
    return 1;	
  }
  //if bl
  else if (pointInRectangle(bx1, by2, x1, x2, y1, y2)) {
    return 1;	
  }
  //if br
  else if (pointInRectangle(bx2, by2, x1, x2, y1, y2)) {
    return 1;	
  }
  //if rectangle is not in rectangle
  else { return 1; }
}

int pointInRectangle(int x, int y, int x1, int x2, int y1, int y2) {
  if (x > x1 && x < x2 && y < y1 && y > y2) {
    return 1; 
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

/*

  TODO:
  set aliveIndex
  set locationIndex

  add to livearray
  add to enemyarray
*/

	
void makeEnemies(int numOfEnemies, struct enemy *enemyArray[], int locationArray[]) {
  int i = 0;		
  //find location in arrayLiveEnemies that is empty/dead, and place enemy
  for (int j = 0; j < MAX_ENEMY; j++) { 
    //if enemy is dead, make new enemy
    if(!locationArray[j]) {
      i++;	
			
      //update locationArray
      locationArray[j] = 1;

      //create enemy and ptr to it
      struct enemy e;
      struct enemy *ePtr = &e;
      enemyArray[j] = ePtr;

      //set location for new enemy using reference to struct object 
      e.locationIndex = j;
//      e.x1 = enemyPositions[j][0];
//      e.x2 = e.x1 + ENEMY_WIDTH;
//      e.y1 = enemyPositions[j][1];
//      e.y2 = e.y1 + ENEMY_HEIGHT;

      e.life = 1;
      e.color = 0x001F;
    }
    else if(j == MAX_ENEMY-1) {
      // printf("Went over max_enemy amount");
      break; }

    if(i == numOfEnemies) { break; } 

		
  }
} 
