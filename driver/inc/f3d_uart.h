/* f3d_uart.h --- 
 * 
 * Filename: f3d_uart.h
 * Description: 
 * Author: Bryce Himebaugh
 * Maintainer: 
 * Created: Thu Sep 26 07:05:43 2013
 * Last-Updated: 
 *           By: Jrod
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

//#include "queue.h"

void f3d_uart_init(void);
int putchar(int);
void flush_uart(void);
int getchar(void);
int getchar2(void);
void putstring(char *);

/* f3d_uart.h ends here */
