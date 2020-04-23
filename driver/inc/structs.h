#include <f3d_lcd_sd.h>

#define PLAYER_Y1 137
#define PLAYER_Y2 147

#define MAX_ENEMY 30

#define CENTERX 63
#define CENTERY 40

#define ENEMY_WIDTH 4
#define ENEMY_HEIGHT 4

//enemies
struct enemy { 
	//ship - image/color
	uint16_t color; //red 0x001F

	//life
	int life; //1 if alive, 0 if dead

	int locationIndex;    //corresponding index to enemyArray if alive or not. For further explanation, look to lines 28-32 of structs.h
	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom
}; // Enemy;

struct enemy *enemyArray[MAX_ENEMY];

int enemyPositions[5][2] = {{CENTERX,CENTERY}, {CENTERX-10,CENTERY+10}, {CENTERX+10,CENTERY-10}, {CENTERX-10,CENTERY-10}, {CENTERX+10,CENTERY+10}};
//TODO: make 30 unique positions


int usedEnemyPositions[MAX_ENEMY];


/*
enemyArray = { e1, e2, e3, e4, ... } list of enemies e1, e2, e3, e4, ...

arryLiveEnemies = { 0, 1, 1, 0, ... } e1 is dead, e2 is alive, e3 is alive, e4 is dead, ...
*/

/*
drawenemies(pointer to array):
	for structPointer in array:
		drawEnemy(structPointer)
*/

//typedef struct enemy Enemy; //https://www.quora.com/What-exactly-does-typedef-do-in-C?share=1  for why i am using typedef to shorten call of struct

//bullet
struct bullet { 
	//bullet - image/color
	uint16_t color; //white 0xFFFF

	//coordinates (it is a vertical line, so no x coord)
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	int shooter; //1 if player, 2 if enemy
}; //Bullet;

//typedef struct bullet Bullet;


//player
struct player { 
	//ship - image/color
	uint16_t color; //blue 0xF800

	//lives
	int lives; //initially set to 3
	int life;  //initially set to 1

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	//score
	int score; //initially set to 0
	//level
	int level; //initially set to 1
};// Player;

//typedef struct player Player;

int checkEnemyCollision(struct bullet *b, struct enemy *e); //Bullet b, Enemy e);

int checkPlayerCollision(struct bullet *b, struct player *p); //Bullet b, Player p);

int ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, int life);

int pointInRectangle(int x, int y, int x1, int x2, int y1, int y2);

void makeEnemies(int numOfEnemies, struct enemy *enemyArray[], int locationArray[]);

