/*
    Aliens
        Only bottom row aliens shoot (randomly?)
        Center dot that all aliens are positioned according to. If dot shifts, then redraw alien shifted according to relation to dot (if dots shifts, alien shifts)
        

Bullets
    Thin vertical line, if x and y dimensions of the line intersect with any part of the area of the line, it will destroy what it hits
    Moves in a
 

    Player
        Lives left, movement left and right , player score
*/

#include <structs.h>

/*//// Collisions ////*/

int checkEnemyCollision(struct bullet b, struct enemy e) {
	if (ifCollision(b.x,b.y,e.x,e.y,e.life)) { e.life = 0; }
}

//checks coordinates, struct type
int checkPlayerCollision(struct bullet b, struct player p) {
	if (ifCollision(b.x,b.y,p.x,p.y,p.life)) { 
		--p.lives;
		if (p.lives <= 0) {
			p.life = 0;
		}
		return 1; //true, there was a collision
	}
	return 0; //false, no collision
}



bool ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, int life) {


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

bool pointInRectangle(int x, int y, int x1, int x2, int y1, int y2) {
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


/*//// Movement ////*/

//    Sends uart serial communication, updates object coordinates based on input, firing bullets
