#include <f3d_lcd_sd.h>

//enemies
struct enemy { 
	//ship - image/color
	int color = RED;

	//life
	bool life = true;

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

}

//bullet
struct bullet { 
	//bullet - image/color
	int color = WHITE;

	//coordinates (it is a vertical line, so no x coord)
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	int shooter; //1 if player, 2 if enemy
}



//player
struct player { 
	//ship - image/color
	int color = BLUE;

	//lives
	int lives = 3;

	bool life = true;

	//coordinates
	int x1,x2; //x1 is left, x2 is right
	int y1,y2; //y1 is top, y2 is bottom

	//score
	int score = 0;
}


bool checkEnemyCollision(struct bullet b, struct enemy e);

bool checkPlayerCollision(struct bullet b, struct player p);

bool ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, bool life);

bool pointInRectangle(int x, int y, int x1, int x2, int y1, int y2);
