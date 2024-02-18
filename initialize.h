#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED

#include <SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

int initialize_window(void);

#endif // INITIALIZE_H_INCLUDED
