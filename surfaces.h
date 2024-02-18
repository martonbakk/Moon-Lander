#ifndef SURFACES_H_INCLUDED
#define SURFACES_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "structs.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FONT "display_font.ttf"

extern SDL_Renderer* renderer;

void dp(bools* igazak, ints* intek, doubles* dbs, karakter* jatekos);
void mentes(bools* igazak, ints* intek, char* nev);
void start();
void menu(bools* igazak, doubles* dbs, ints* intek, Time* ido, karakter* jatekos);
void game_over(bools* igazak, doubles* dbs, ints* intek, Time* ido, karakter* jatekos);
void win(bools* igazak, doubles* dbs, ints* intek, Time* ido, karakter* jatekos);
void tabella();
void background(bgr* backg, bgr* backg2);


#endif // SURFACES_H_INCLUDED
