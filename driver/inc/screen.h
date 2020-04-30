#include <f3d_lcd_sd.h>
#include <structs.h>
#include <helpers.h>


void drawStartScreen(void);
void drawEndLevelScreen(struct player *playerPtr);
void drawEndScreen(struct player *p);  

void drawBackground(struct player *p);
void drawPlayerStats(struct player *p);

void drawPlayer(struct player *p);
void erasePlayer(struct player *p);

void drawEnemy(struct enemy e);
void eraseEnemy(struct enemy e);
void eraseEnemyIndex(struct enemy e[], int enemyIndex);

void drawEnemies(struct enemy e[], int liveEnemy[]);
void eraseEnemies(struct enemy e[], int liveEnemy[]);

void drawBullet(struct bullet *b);
void eraseBullet(struct bullet *b);

void drawBullets(struct bullet b[], int liveBullet[]);
void eraseBullets(struct bullet b[], int liveBullet[]);

void shoot(struct bullet bArray[], int liveBullets[]);

void movePlayer(struct player *p, int input);
void moveEnemies(struct player *pPtr, struct enemy eArr[], int liveE[]);
void moveEnemiesTwo(struct player *pPtr, struct enemy eArr[], int liveE[]);

int randomNumberGen(int ,int);
void enemyShoot(struct enemy eArray[], int liveEnemies[], struct player *p, struct bullet bArray[], int liveBullets[]);

void drawAll(struct player *playerPtr, struct enemy e[], int liveEnemy[], struct bullet b[], int liveBullet[]);
