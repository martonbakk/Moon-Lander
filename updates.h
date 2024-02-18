#ifndef UPDATES_H_INCLUDED
#define UPDATES_H_INCLUDED

#include <stdbool.h>
#include <SDL.h>
#include "structs.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

void tav(doubles *dbs, karakter* jatekos, SDL_Point* pont_tomb);
fuel_tomb* ujmeret_fuel_tomb(int ujhosz, fuel_tomb **uzem);
void figura(karakter* jatekos, ints* intek);
void idozito(Time* ido, doubles* dbs);
void update(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter* jatekos, bgr* backg, bgr* backg2, SDL_Point* pont_tomb, fuel_tomb** uzem);



#endif // UPDATES_H_INCLUDED
