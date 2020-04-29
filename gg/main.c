/*
* main.c for galaga
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper
*/





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
#include <stm32f30x.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_i2c.h>
#include <f3d_delay.h>
#include <f3d_systick.h>
#include "queue.h"
#include <f3d_uart.h>
#include <screen.h>
#include <state.h>

void start(void){
	f3d_lcd_init();
	f3d_uart_init();
	f3d_systick_init();

	//set all values of arrayLiveEnemies and usedEnemyPosiitons to zero (for more info look at lines 28-32 in structs.h)
	for (int i = 0; i < MAX_ENEMY; i++) { usedEnemyPositions[i] = 0; }
	for (int i = 0; i < MAX_BULLET; i++) { usedBulletPositions[i] = 0; }

	//draw GALAGA text and instructions how to play
	drawStartScreen(); 

	//press any key, then break
//	while(1) {
//		if(getchar()) { break; }
//	}



}
void init_game(void){
	//create new player
	pPtr = &p1;

	p1.color = 0xF800;
	p1.lives = 3;
	p1.life = 1;
	p1.x1 = 63;
	p1.x2 = p1.x1+4;
	p1.y1 = PLAYER_Y1;
	p1.y2 = PLAYER_Y2;
	p1.score = 66;
	p1.level = 0;

	makeEnemies(29, enemyArray, usedEnemyPositions); //create initial first 5 enemies


//	putchar(enemyArray[i]->locationIndex + '0');
//	printf("### life of enemy is: %d ###", enemyArray[i]->life);

}
void end(void){


}
int game(void){
	int c; /* current character */

	//game() sets screen to "start game display" that shows game title, basic instructions, and waits for user to enter a space to begin
	//also initializes all hardware components
	start();

	static int state = SETT;
	
	while(1) {
		switch(state) {
		case SETT: //set or reset initial player/enemy values of the game
			init_game();
			state = GAME;
			break;
		case GAME: //
			//check for collisions
			//TODO: checkCollision();

		        // if(up arrow || W || w){makeBullet();}
		       

			//move objects
		        //
		        //shoot(); //this will update positions of bullets that have already been made
		  //makeBullet(pPtr, bulletArray, usedBulletPositions);
		  //shoot(bulletArray, usedBulletPositions);

			//check for input
			if (c = getchar2()) { //have to hold key to move
				movePlayer(pPtr,c);
			}

			//update display
			drawAll(pPtr, enemyArray, usedEnemyPositions, bulletArray, usedBulletPositions);


	
			break;
		//case PAUSE: //pauses game "time"
		//case EXIT: //ends and exits game
		}
	}

}

int main(void) { game(); return 1; }


/*
* main.c for galaga
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper
*/

void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}

