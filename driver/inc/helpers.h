/*helpers.h*/
float radianToDegree(float rad);
float get_pitch(float accel_data[]);
float get_roll(float accel_data[]);
float get_heading(float mag_data[]);
void drawBar_vertical(int start_x, int start_y ,int end ,uint16_t colour);
void drawBar_horizontal(int start_x, int start_y ,int end ,uint16_t colour);
void angle_visual(float pitch, float roll);
void compass_visual(float heading);
void drawBar(int start_x, int start_y ,int end ,uint16_t colour);
void displayGyroGraph(float x_pos, float y_pos, float z_pos);
void nunchuk_tilt_visual(int x, int y, int z);
