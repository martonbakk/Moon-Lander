#include "render.h"


void render(bools *igazak, doubles *dbs, ints *intek, poly *poligon, Time* ido, karakter *jatekos, bgr* backg, bgr* backg2, char* nev, ListaElem* eleje, fuel_tomb* uzem)
{
    // Hatter
    background(backg, backg2);

    SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);

    // Palya
    filledPolygonRGBA(renderer, poligon->polyx, poligon->polyy, 30, 255, 255, 255, 255);

    // Leszallopalya
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, intek->le_x1, intek->le_y1, intek->le_x2, intek->le_y2);
    SDL_RenderDrawLine(renderer, intek->le_x1 + 5, intek->le_y1 + 5, intek->le_x2 - 5, intek->le_y2 + 5);

    //display
    dp(igazak,intek, dbs, jatekos);

    // Hajtomu
    for (int i = 1; i < intek->hosz; i++)
    {
        if (uzem[i].opicaty > 10)
        {
            filledCircleRGBA(renderer, uzem[i].x, uzem[i].y, 5, 255, 255, 255, uzem[i].opicaty);
        }
    }

    // Figura
    if (igazak->presstostart && !igazak->game_o)
    {
        figura(/*igazak, */jatekos, intek);
    }

    // Menu
    if (igazak->menu_mutat)
    {
        menu(igazak, dbs, intek, ido, jatekos);
    }



    // Kezdes
    if (!igazak->presstostart)
    {
        start(igazak);
    }

    // Vege
    if (igazak->game_o || jatekos->x > WINDOW_WIDTH + 50 || jatekos->x + 50 < 0 || jatekos->y + 50 < 0)
    {
        game_over(igazak, dbs, intek, ido, jatekos);
    }


    // Winner
    if (igazak->winner_mutat)
    {
        win(igazak, dbs, intek, ido, jatekos);
    }
    // Tabella
    if (igazak->tabella_mut)
    {
        tabella();
        tabella_fel(igazak, intek, eleje);
    }
    size_t len=strlen(nev);
    if(len>1){
    SDL_Log("%s", nev);
    }
    if(igazak->mentes&&igazak->beiras){
        mentes(igazak,intek, nev);
    }
    SDL_RenderPresent(renderer);
}
