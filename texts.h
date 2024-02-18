#ifndef TEXTS_H_INCLUDED
#define TEXTS_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include "structs.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FONT "display_font.ttf"

extern SDL_Renderer* renderer;

void display_fel(doubles *dbs, ints *intek, karakter *jatekos);
void game_over_fel(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter *jatekos);
void menu_fel(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter *jatekos);
void win_fel(bools *igazak, doubles *dbs, ints *intek, Time *ido, karakter *jatekos);
void tabella_fel(bools *igazak, ints *intek, ListaElem **eleje);
void mentes_beiras(ints* intek, bools* igazak, SDL_Rect* uzenet, char* nev);

#endif // TEXTS_H_INCLUDED
