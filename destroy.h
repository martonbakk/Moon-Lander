#ifndef DESTROY_H_INCLUDED
#define DESTROY_H_INCLUDED

#include <stdlib.h>
#include <SDL.h>
#include "lista.h"
#include "structs.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

void destroy_window(bools* igazak, ListaElem** eleje, fuel_tomb** uzem);

#endif // DESTROY_H_INCLUDED
