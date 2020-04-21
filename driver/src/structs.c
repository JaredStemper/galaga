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

//TODO should this function be void? or is there another check that needs to be done afterwards
int checkEnemyCollision(struct bullet b, struct enemy e) {
	//if collision, set life to 0 and return 1 (for true)
	if (ifCollision(b.x1,b.x2, b.y1,b.y2, e.x1,e.x2, e.y1,e.y2, e.life)) { 
		e.life = 0;
		return 1; //true, there was a collision
	}
	return 0; //false, no collision
}

//checks coordinates, struct type
int checkPlayerCollision(struct bullet b, struct player p) {
	if (ifCollision(b.x1,b.x2, b.y1,b.y2, p.x1,p.x2, p.y1,p.y2, p.life)) { 
		--p.lives;
		if (p.lives <= 0) {
			p.life = 0;
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

