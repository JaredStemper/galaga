#include <f3d_lcd_sd.h>


//enemies
struct enemy { 
	//ship - image/color
	uint16_t color = 0x001F;//red

	//life
	int life = 1;

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

};

//bullet
struct bullet { 
	//bullet - image/color
	uint16_t color = 0xFFFF; //white

	//coordinates (it is a vertical line, so no x coord)
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	int shooter; //1 if player, 2 if enemy
};



//player
struct player { 
	//ship - image/color
	uint16_t color = 0xF800; //blue

	//lives
	int lives = 3;
	int life = 1;

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	//score
	int score = 0;
	//level
	int level = 1;
};


int checkEnemyCollision(struct bullet b, struct enemy e);

int checkPlayerCollision(struct bullet b, struct player p);

int ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, int life);

int pointInRectangle(int x, int y, int x1, int x2, int y1, int y2);
