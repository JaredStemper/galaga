/*Helper Functions from previous labs*/

#include <stdio.h>
#include <math.h>
#include <f3d_lcd_sd.h>

float radianToDegree(float rad){return rad*180/M_PI; }

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


void drawBar(int start_x, int start_y ,int end ,uint16_t colour){
  
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
int y_upper=35;
int y_lower=152;
int vert_mid=92;
int y_mid=63; int x_mid=31; int z_mid=91;

void displayGyroGraph(float x_pos, float y_pos, float z_pos){
  /*for X bar*/
  if(x_pos>0 && x_pos<=10){
    drawBar(x_mid, x_mid+1, y_lower, BLACK);
    drawBar(x_mid, vert_mid, 73, YELLOW);
    drawBar(x_mid, 74, y_upper, BLACK);
  }
  if(x_pos>10 && x_pos<=60){
    drawBar(x_mid, x_mid+1, y_lower, BLACK);
    drawBar(x_mid, vert_mid, 54, YELLOW);
    drawBar(x_mid, 55, y_upper, BLACK);
  }
  if(x_pos>60){
    drawBar(x_mid, x_mid+1, y_lower, BLACK);
    drawBar(x_mid, vert_mid, y_upper, YELLOW);
  } 
  ///negatives
  if(x_pos<0 && x_pos>-10){
    drawBar(x_mid, vert_mid-1, y_upper, BLACK);
    drawBar(x_mid, vert_mid, 112, YELLOW);
    drawBar(x_mid, 113, y_lower, BLACK);
  }
  if(x_pos<-10 && x_pos>-60){
    drawBar(x_mid, vert_mid-1, y_upper, BLACK);
    drawBar(x_mid, vert_mid, 132, YELLOW);
    drawBar(x_mid, 133, y_lower, BLACK);
  }
  if(x_pos<-60){
    drawBar(x_mid, vert_mid-1, y_upper, BLACK);
    drawBar(x_mid, vert_mid, y_lower, YELLOW);
  }
  /*for Y bar*/
  if(y_pos>0 && y_pos<=10){
    drawBar(y_mid, y_mid+1, y_lower, BLACK);
    drawBar(y_mid, vert_mid, 73, CYAN);
    drawBar(y_mid, 74, y_upper, BLACK);
  }
  if(y_pos>10 && y_pos<=60){
    drawBar(y_mid, y_mid+1, y_lower, BLACK);
    drawBar(y_mid, vert_mid, 54, CYAN);
    drawBar(y_mid, 55, y_upper, BLACK);
  }
  if(y_pos>60){
    drawBar(y_mid, y_mid+1, y_lower, BLACK);
    drawBar(y_mid, vert_mid, y_upper, CYAN);
  } 
  ///negatives
  if(y_pos<0 && y_pos>-10){
    drawBar(y_mid, vert_mid-1, y_upper, BLACK);
    drawBar(y_mid, vert_mid, 112, CYAN);
    drawBar(y_mid, 113, y_lower, BLACK);
  }
  if(y_pos<-10 && y_pos>-60){
    drawBar(y_mid, vert_mid-1, y_upper, BLACK);
    drawBar(y_mid, vert_mid, 132, CYAN);
    drawBar(y_mid, 133, y_lower, BLACK);
  }
  if(y_pos<-60){
    drawBar(y_mid, vert_mid-1, y_upper, BLACK);
    drawBar(y_mid, vert_mid, y_lower, CYAN);
  }
  
  /*for Z bar*/
   if(z_pos>0 && z_pos<=10){
    drawBar(z_mid, z_mid+1, y_lower, BLACK);
    drawBar(z_mid, vert_mid, 73, GREEN);
    drawBar(z_mid, 74, y_upper, BLACK);
  }
  if(z_pos>10 && z_pos<=60){
    drawBar(z_mid, z_mid+1, y_lower, BLACK);
    drawBar(z_mid, vert_mid, 54, GREEN);
    drawBar(z_mid, 55, y_upper, BLACK);
  }
  if(z_pos>60){
    drawBar(z_mid, z_mid+1, y_lower, BLACK);
    drawBar(z_mid, vert_mid, y_upper, GREEN);
  } 
  ///negatives
  if(z_pos<-0 && z_pos>-10){
    drawBar(z_mid, vert_mid-1, y_upper, BLACK);
    drawBar(z_mid, vert_mid, 112, GREEN);
    drawBar(z_mid, 113, y_lower, BLACK);
  }
  if(z_pos<-10 && z_pos>-60){
    drawBar(z_mid, vert_mid-1, y_upper, BLACK);
    drawBar(z_mid, vert_mid, 132, GREEN);
    drawBar(z_mid, 133, y_lower, BLACK);
  }
  if(z_pos<-60){
    drawBar(z_mid, vert_mid-1, y_upper, BLACK);
    drawBar(z_mid, vert_mid, y_lower, GREEN);
  }
}

void nunchuk_tilt_visual(int x, int y, int z){
  int roll = atan(y/(sqrt((x*x)+(z*z))));
  int pitch = atan(x/(sqrt((y*y)+(z*z))));
    
  /*  if(0>pitch){
    drawBar_vertical(x_cen, y_cen+4, y_max, CYAN);
    drawBar_vertical(x_cen, y_cen-4, y_min, BLACK);
  }
  if(0<pitch){
    drawBar_vertical(x_cen, y_cen-4, y_min, CYAN);
    drawBar_vertical(x_cen, y_cen+4, y_max, BLACK);
  }

  if(0>roll){
    drawBar_horizontal(x_cen+4, y_cen, x_max, GREEN);
    drawBar_horizontal(x_cen-4, y_cen, x_min, BLACK);
  }
  if(0<roll){
    drawBar_horizontal(x_cen-4, y_cen, x_min, GREEN);
    drawBar_horizontal(x_cen+4, y_cen, x_max, BLACK);
    } */
  
}


/*helpers.c ends here*/
