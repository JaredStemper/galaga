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

bool checkEnemyCollision(struct bullet b, struct enemy e) {
	if (ifCollision(b.x,b.y,e.x,e.y,e.life)) { e.life = false; }
}

//checks coordinates, struct type
bool checkPlayerCollision(struct bullet b, struct player p) {
	if (ifCollision(b.x,b.y,p.x,p.y,p.life)) { 
		--p.lives;
		if (p.lives <= 0) {
			p.life = false;
		}
	}
}



bool ifCollision(int bx1, int bx2, int by1, int by2, int x1, int x2, int y1, int y2, bool life) {


	//if life is false, don't check
	if(!life) { return false }
	//if tl
	else if(pointInRectangle(bx1, by1, x1, x2, y1, y2)) {
		return true;
	}
	//if tr
	else if (pointInRectangle(bx2, by1, x1, x2, y1, y2)) {
		return true;	
	}
	//if bl
	else if (pointInRectangle(bx1, by2, x1, x2, y1, y2)) {
		return true;	
	}
	//if br
	else if (pointInRectangle(bx2, by2, x1, x2, y1, y2)) {
		return true;	
	}
	//if rectangle is not in rectangle
	else { return false; }
}

bool pointInRectangle(int x, int y, int x1, int x2, int y1, int y2) {
	if (x > x1 && x < x2 && y < y1 && y > y2) {
		return true; 
	}

	return false;
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
