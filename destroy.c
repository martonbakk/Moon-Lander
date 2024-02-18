#include "destroy.h"

void destroy_window(bools* igazak, ListaElem** eleje, fuel_tomb** uzem)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    free(*uzem);
    lista_felszabaditas(*eleje);
}
