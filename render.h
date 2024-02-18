#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include "structs.h"
#include <SDL2_gfxPrimitives.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

extern SDL_Renderer* renderer;
void render(bools *igazak, doubles *dbs, ints *intek, poly *poligon, Time *ido, karakter *jatekos, bgr *backg, bgr *backg2, char *nev, ListaElem *eleje, fuel_tomb *uzem);


#endif // RENDER_H_INCLUDED
