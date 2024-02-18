#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "structs.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void setup(bools *igazak, doubles *dbs, ints *intek, poly *poligon, Time* ido, karakter *jatekos, char* nev, ListaElem **eleje, SDL_Point* pont_tomb, fuel_tomb** uzem);

#endif // SETUP_H_INCLUDED
