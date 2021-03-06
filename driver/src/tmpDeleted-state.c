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
#include <f3d_user_btn.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_i2c.h>
#include <f3d_delay.h>
#include <f3d_uart.h>
#include <screen.h>
#include <state.h>

void start(void){
	f3d_lcd_init();

	//set all values of arrayLiveEnemies and usedEnemyPosiitons to zero (for more info look at lines 28-32 in structs.h)
	for (int i = 0; i < MAX_ENEMY; i++) { usedEnemyPositions[i] = 0; }


	makeEnemies(5, enemyArray, usedEnemyPositions); //create initial first 5 enemies

	//draw GALAGA text and instructions how to play
	drawStartScreen(); delay(10000);
	
	//if user hits space bar, then break
//	while(1) {}


}
void init_game(void){
	//create new player
	struct player p1;
	struct player *pPtr = &p1;

	p1.color = 0xF800;
	p1.lives = 3;
	p1.life = 1;
	p1.x1 = 63;
	p1.x2 = p1.x1+4;
	p1.y1 = PLAYER_Y1;
	p1.y2 = PLAYER_Y2;
	p1.score = 0;
	p1.level = 0;


	//create bullet
	struct bullet b1;
	struct bullet *bPtr = &b1;
	b1.x1 = 63;
	b1.x2 = b1.x1+2;
	b1.y1 = 100;
	b1.y2 = b1.y1+4;
	drawBullet(bPtr);

	//create new initial enemy
	struct enemy e1;
	struct enemy *ePtr = &e1;
	e1.color = 0x001F;
	e1.life = 1;
	//create initial array of enemies


	drawBackground(pPtr);
	drawPlayer(pPtr);
	drawEnemy(ePtr);
	drawBullet(bPtr); //TODO: create shoot function


}
void end(void){


}
int game(void){
	//set screen to "start game display" that shows game title, basic instructions, and waits for user to enter a space to begin
	//also initializes all hardware components
	start();

	static int state = SET;
	
//	while(1) {
		switch(state) {
		case SET: //set or reset initial player/enemy values of the game
			init_game();
			state = GAME;
			break;
		case GAME: //
			//check for collisions
			//check for input
			//move objects
			break;
		//case PAUSE: //pauses game "time"
		//case EXIT: //ends and exits game
		}
		//update display
//	}

}

int main(void) { game(); return 1; }
