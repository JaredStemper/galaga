#include <f3d_lcd_sd.h>
#include <structs.h>
#include <helpers.h>


void drawStartScreen(void);

void drawBackground(struct player *p);

void drawPlayer(struct player *p);

void drawEnemy(struct enemy *e);

void drawEnemies(struct enemy *e[]);

void drawBullet(struct bullet *b);
