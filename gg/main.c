/*
* main.c for lab 7
* Author(s)/Editor(s): Kunal Atul Pendse, Jared Stemper, Ray Lopez
*/

//#include <stdio.h>
//#include <stdlib.h>
#include <f3d_user_btn.h>
#include <f3d_lcd_sd.h>
#include <f3d_accel.h>
#include <f3d_mag.h>
#include <f3d_i2c.h>
#include <f3d_delay.h>
#include <f3d_uart.h>
#include <math.h>

float radianToDegree(float rad){return rad*180/M_PI; }

/*prints raw accel data*/
void accel_rep(float data[]){
  f3d_accel_read(data);
  // printf("accel: x:%4.4f y:%4.4f z:%4.4f \n", data[0], data[1], data[2]); //uncomment only while debugging
}

  /*prints raw mag data*/
void mag_rep(float data[]){
  f3d_mag_read(data);
  // printf("gyro: x:%4.4f y:%4.4f \n", data[0], data[1]); //uncomment only while debugging
  
}

float get_pitch(float accel_data[]){
  float pitch;
  pitch = atanf(accel_data[0]/ (sqrt(pow(accel_data[1],2)+pow(accel_data[2],2))));
  return pitch;
}
float get_roll(float accel_data[]){
  float roll;
  roll = atanf(accel_data[1]/ (sqrt(pow(accel_data[0],2)+pow(accel_data[2],2))));
  return roll;
}

float get_heading(float mag_data[]){
  float heading;  
  heading = radianToDegree(atan2f(mag_data[1],mag_data[0]));
  heading = heading + 180;
  return heading;
}

float get_heading_TC(float mag_data[], float accel_data[]){
  float pitch = get_pitch(accel_data);
  float roll = get_roll(accel_data);
  float x = mag_data[0]*cos(pitch) + mag_data[2]*sin(pitch);
  float y = mag_data[0]*sin(roll)*sin(pitch) + mag_data[0]*cos(roll) - mag_data[2]*sin(roll)*cos(pitch);

  float heading = 180 + radianToDegree(atan2f(y,x));
  return heading;

}
/*---------------------------Visualization Functions---------------------------*/
void drawBar_vertical(int start_x, int start_y ,int end ,uint16_t colour){
  
  if(start_y>end){
    int i;
    for(i=start_y; i>=end; i--){
      f3d_lcd_drawPixel(start_x, i, colour); f3d_lcd_drawPixel(start_x+2, i, colour);
      f3d_lcd_drawPixel(start_x+1, i, colour);f3d_lcd_drawPixel(start_x+3, i, colour);
    }
  }
  int i;
  for(i=start_y; i<=end; i++){
    f3d_lcd_drawPixel(start_x, i, colour); f3d_lcd_drawPixel(start_x+2, i, colour);
    f3d_lcd_drawPixel(start_x+1, i, colour);f3d_lcd_drawPixel(start_x+3, i, colour);
  }
  
}

void drawBar_horizontal(int start_x, int start_y ,int end ,uint16_t colour){
  if(start_x>end){
    int i;
    for(i=start_x; i>=end; i--){
      f3d_lcd_drawPixel(i, start_y, colour);f3d_lcd_drawPixel(i, start_y+2, colour);
      f3d_lcd_drawPixel(i, start_y+1, colour);f3d_lcd_drawPixel(i, start_y+3, colour);
    }
  }
  int i;		   
  for(i=start_x; i<=end; i++){
    f3d_lcd_drawPixel(i, start_y, colour);f3d_lcd_drawPixel(i, start_y+2, colour);
    f3d_lcd_drawPixel(i, start_y+1, colour);f3d_lcd_drawPixel(i, start_y+3, colour);
    }
}

int x_cen=63; int y_cen=79;
int x_min=0; int y_min = 0;
int x_max=127; int y_max = 159;

void angle_visual(float pitch, float roll){
  if(0>pitch){
    drawBar_vertical(x_cen, y_cen+4, y_max, RED);
    drawBar_vertical(x_cen, y_cen-4, y_min, BLACK);
  }
  if(0<pitch){
    drawBar_vertical(x_cen, y_cen-4, y_min, RED);
    drawBar_vertical(x_cen, y_cen+4, y_max, BLACK);
  }

  if(0>roll){
    drawBar_horizontal(x_cen+4, y_cen, x_max, YELLOW);
    drawBar_horizontal(x_cen-4, y_cen, x_min, BLACK);
  }
  if(0<roll){
    drawBar_horizontal(x_cen-4, y_cen, x_min, YELLOW);
    drawBar_horizontal(x_cen+4, y_cen, x_max, BLACK);
  } 
}


void compass_visual(float heading){
  int nx = 63; int sx = 63; int ex = 63+40; int wx = 63-40;
  int ny = 79-40; int sy = 79+40; int ey=79; int wy=79;
  int nex = 63+22; int nwx = 63-22; int sex = 63+22; int swx = 63-22;
  int ney = 79-23; int nwy = 79-23; int sey = 79+23; int swy = 79+23;                            

  if(0<=heading && heading<22.5 || 337.5<=heading && heading<=360){
    f3d_lcd_drawChar(nx,ny,'N',CYAN,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
    //interms
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
  }
  if(22.5<=heading && heading<67.5){//mid
    f3d_lcd_drawString(nex,ney,"NE",CYAN,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
    //mains
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
  }
  if(67.5<=heading && heading<112.5){
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',CYAN,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
    //interms
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
  }
  if(112.5<=heading && heading<157.5){//mid
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",CYAN,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
    //mains
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
  }
  if(157.5<=heading && heading<205.5){
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',CYAN,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
    //interms
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
  }
  if(205.5<=heading && heading<247.5){//mid
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",CYAN,BLACK);
    //mains
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
  }
  if(247.5<=heading && heading<292.5){
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',CYAN,BLACK);
    //interms
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",RED,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
  }
  if(292.5<=heading && heading<337.5){//mid
    f3d_lcd_drawString(nex,ney,"NE",RED,BLACK);f3d_lcd_drawString(sex,sey,"SE",RED,BLACK);
    f3d_lcd_drawString(nwx,nwy,"NW",CYAN,BLACK);f3d_lcd_drawString(swx,swy,"SW",RED,BLACK);
    //mains
    f3d_lcd_drawChar(nx,ny,'N',RED,BLACK);f3d_lcd_drawChar(sx,sy,'S',RED,BLACK);
    f3d_lcd_drawChar(ex,ey,'E',RED,BLACK);f3d_lcd_drawChar(wx,wy,'W',RED,BLACK);
  }
}
/*-------------------------------------------------------------------------------------------------*/
int main(void){
  /*intializations*/
  user_btn_init();
  f3d_uart_init();
  f3d_lcd_init();
  f3d_i2c1_init();
  delay(10);
  f3d_accel_init();
  delay(10);
  f3d_mag_init();
  delay(10);
  float mag_data[3];
  float accel_data[3];
  int switcher=0;
  /*--------------*/
  f3d_lcd_fillScreen2(BLACK);
  while(1){    
    f3d_accel_read(accel_data);
    f3d_mag_read(mag_data);
    
    if(user_btn_read()){
      switcher++;
      f3d_lcd_fillScreen2(BLACK);
      if(switcher==2){switcher=0;}
    }
    
    switch(switcher){
    case 0: compass_visual(get_heading(mag_data));
      break;
    case 1: angle_visual(get_pitch(accel_data), get_roll(accel_data));
      break;
    }
  }

  return 0;
}

void assert_failed(uint8_t* file, uint32_t line) {
/* Infinite loop */
/* Use GDB to find out why we're here */
  while (1);
}
