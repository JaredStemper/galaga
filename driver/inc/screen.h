#include <f3d_lcd_sd.h>
#include <structs.h>
#include <helpers.h>


void drawStartScreen(void);

void drawBackground(struct player *p);

void drawPlayer(struct player *p);
void erasePlayer(struct player *p);

void drawEnemy(struct enemy e);
void eraseEnemy(struct enemy e);

void drawEnemies(struct enemy e[], int liveEnemy[]);
void eraseEnemies(struct enemy e[], int liveEnemy[]);

void drawBullet(struct bullet *b);
void eraseBullet(struct bullet *b);

void drawBullets(struct bullet b[], int liveBullet[]);
void eraseBullets(struct bullet b[], int liveBullet[]);

void shoot(struct bullet bArray[], int liveBullets[]);

void movePlayer(struct player *p, int input);
void moveEnemies(struct player *pPtr);


void drawAll(struct player *playerPtr, struct enemy e[], int liveEnemy[], struct bullet b[], int liveBullet[]);
