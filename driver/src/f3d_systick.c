/* f3d_systick.c --- 
 * 
 * Filename: f3d_systick.c
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Thu Nov 14 07:57:37 2013
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2004-2007 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */

#include <f3d_systick.h>
#include <f3d_user_btn.h>
#include <f3d_uart.h>

volatile int systick_flag = 0;

int ips = 12;


void f3d_systick_init(void) {
/*
	from p.169 of manual

	Function to setup the initial rate of timer
	function should pass the number of interrupts per second in as the divisor to the SysTick_Config functio

	For example, this call would produce generate 12 interrupts per second:
		SysTick_Config(SystemCoreClock/12);
*/


	SysTick_Config(SystemCoreClock/ips);

}


//void SysTick_Config(int) {


//}


void SysTick_Handler(void) {
/*
	This handler is call on each interrupt. When this function is run, it clears the pending interrupt from the systick timer. 
		Your code does not need to clear any systick flags.
*/	

//basically main, when the button is pressed, slow down
    
//	if(!user_btn_read()) {
//		ips = 100;
		SysTick_Config(SystemCoreClock/ips);
//	}
//	else {
		ips = 12;
//		SysTick_Config(SystemCoreClock/ips);		
//	}	

	
}

/* f3d_systick.c ends here */
//systick handler, when working. comment it out (empty handler). modify uart.c with putchar getchar onque and deque 
