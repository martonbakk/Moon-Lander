#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// SDL2 headerek
#include <SDL.h>
#include <SDL_timer.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

// debug malloc
#include "debugmalloc.h"

//sajat headerek
#include "structs.h"
#include "setup.h"
#include "lista.h"
#include "initialize.h"
#include "updates.h"

int main(int argc, char *argv[])
{
    bools igazak;
    doubles dbs;
    ints intek;
    poly poligon;
    karakter jatekos;
    bgr backg, backg2;
    SDL_Point pont_tomb[30];
    fuel_tomb *uzem=NULL;

    ListaElem *eleje=NULL;
    char nev[30];
    Time ido;

    srand(time(0));
    igazak.game_is_running = initialize_window();
    setup(&igazak, &dbs, &intek, &poligon, &ido, &jatekos, nev, &eleje, pont_tomb, &uzem);
    while (igazak.game_is_running)
    {
        processe_input(&igazak, &intek, &nev);
        update(&igazak, &dbs, &intek, &ido, &jatekos, &backg, &backg2, pont_tomb, &uzem);
        render(&igazak, &dbs, &intek, &poligon, &ido, &jatekos, &backg, &backg2, nev, eleje, uzem);
        save(&eleje, nev, &intek, ido, &igazak);
    }
    destroy_window(&igazak, &eleje, &uzem);
    return 0;
}
