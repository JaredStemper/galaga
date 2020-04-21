/*
init()
	Starts with 0 score, 3 lives, etc.
Start screen
	Big letters galaga with additional text to hit space to begin
During game
	Updates constantly, checks for collisions/input
	Enemies shoot 
	Enemies move (in tandem)
Game end
	If lives are 0:
		Show game over in big red letters
	Else:
		Say good job

	show score, hit space to play again (runs init()) and goes to during game
*/

#include <state.h>

//enum {INIT, START, GAME, EXIT}

void init_game(void){
	//create new player
	struct player p1;
	p1.color = 0xF800;
	p1.lives = 3;
	p1.life = 1;
	p1.x1 = 40;
	p1.x2 = 45;
	p1.y1 = 140;
	p1.y2 = 145;
	p1.score = 0;
	p1.level = 0;

	//create new initial enemy
	struct enemy e1;
	e1.color = 0x001F;
	e1.life = 1;

	//create initial array of enemies
}
void start(void){


}
void end(void){


}
int game(void){
	static int state = INIT;
	
	while(1) {
		switch(state) {
		case INIT: //set or reset initial values of the game
			//stuff
		case START: //set screen to "start game display" that shows game title, basic instructions, and waits for user to enter a space to begin
			//if space is pressed, change state to GAME
			state = GAME;
		case GAME: //
			//check for collisions
			//check for input
		//case PAUSE: //pauses game "time"
		//case EXIT: //ends and exits game
		}
	}

}

