#include <f3d_lcd_sd.h>


//enemies
struct enemy { 
	//ship - image/color
	uint16_t color; //red 0x001F

	//life
	int life; //1 if alive, 0 if dead

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom
}; // Enemy;

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

int checkEnemyCollision(struct bullet b, struct enemy e); //Bullet b, Enemy e);

int checkPlayerCollision(struct bullet b, struct player p); //Bullet b, Player p);

int ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, int life);

int pointInRectangle(int x, int y, int x1, int x2, int y1, int y2);
