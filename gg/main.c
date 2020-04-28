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

//	drawBackground(pPtr);


	//create bullet
	struct bullet b1;
	struct bullet *bPtr = &b1;
	b1.x1 = 63;
	b1.x2 = b1.x1+2;
	b1.y1 = 100;
	b1.y2 = b1.y1+4;


	//create new initial enemy
	struct enemy e1;
	struct enemy *ePtr = &e1;
	e1.x1 = 63;
	e1.x2 = e1.x1+4;
	e1.y1 = PLAYER_Y1;
	e1.y2 = PLAYER_Y2;
	e1.color = 0x001F;
	e1.life = 1;


	struct enemy e2;
	struct enemy *e2Ptr = &e2;
	e2.x1 = 43;
	e2.x2 = e2.x1+4;
	e2.y1 = PLAYER_Y1-20;
	e2.y2 = PLAYER_Y2-20;
	e2.color = 0x001F;
	e2.life = 1;

	makeEnemies(5, enemyArray, usedEnemyPositions); //create initial first 5 enemies TODO: fix this


	//create initial array of enemies
/*
	enemyArray[0] = &e1;
	enemyArray[1] = &e2;

	usedEnemyPositions[0]=1;
	usedEnemyPositions[1]=1;
*/

//while loop used to test value of characters using screen
//while(1){

/*
	putchar(enemyArray[0]->locationIndex + '0');
	putchar(enemyArray[1]->locationIndex + '0');
	putchar(enemyArray[2]->locationIndex + '0');
	putchar(enemyArray[3]->locationIndex + '0');
	putchar(enemyArray[4]->locationIndex + '0');
*/



	for (int i=0; i<10; i++) {
//		putchar(enemyArray[i]->locationIndex + '0');
//		printf("### life of enemy is: %d ###", enemyArray[i]->life);
	}
//}

//		putchar(usedEnemyPositions[i]+'0'); //given ascii value of character, it gets confused. 
			//instead give it the integer and then typcast it using a following character
//		printf("%d",usedEnemyPositions[i]);









/*	bulletArray[0] = &b1;
	usedBulletPositions[0]=1;
*/
		



	


}
void end(void){


}
int game(void){
	//game() sets screen to "start game display" that shows game title, basic instructions, and waits for user to enter a space to begin
	//also initializes all hardware components
	start();

	static int state = SETT;
	
//	while(1) {
		switch(state) {
		case SETT: //set or reset initial player/enemy values of the game
			init_game();
			state = GAME;
			break;
		case GAME: //
			//check for collisions
			//TODO: checkCollision();

			//check for input

			//move objects


			//update display
			drawAll(pPtr, enemyArray, usedEnemyPositions, bulletArray, usedBulletPositions);


	
			break;
		//case PAUSE: //pauses game "time"
		//case EXIT: //ends and exits game
		}
//	}

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

