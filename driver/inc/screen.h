#include <f3d_lcd_sd.h>
#include <structs.h>
#include <helpers.h>


void drawStartScreen(void);

void drawBackground(struct player *p);

void drawPlayer(struct player *p);

void drawEnemy(struct enemy e);

void drawEnemies(struct enemy e[], int liveEnemy[]);

void drawBullet(struct bullet *b);

void drawBullets(struct bullet b[], int liveBullet[]);

void makeBullet(struct player *playerPtr, struct bullet bArray[], int liveBullets[]);

void shoot(struct bullet bulletArray[], int liveBullets[]);
  
void drawAll(struct player *playerPtr, struct enemy e[], int liveEnemy[], struct bullet b[], int liveBullet[]);
