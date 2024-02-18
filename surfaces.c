#include "surfaces.h"

void dp(bools* igazak, ints* intek, doubles* dbs, karakter *jatekos)
{
    // Kijelzo
    SDL_Rect kijelzo = {
        (int)display.x,
        (int)display.y,
        (int)display.width,
        (int)display.height};

    // Display
    if (igazak->presstostart)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
        SDL_RenderFillRect(renderer, &kijelzo);

        // Feliratok
        display_fel(dbs, intek, jatekos);

        // Fuel jelzoallapot, leszalhat-e
        if (jatekos->y > (intek->le_y2 - 100) && (jatekos->x >= intek->le_x1) && (jatekos->x <= intek->le_x2))
        {
            filledCircleRGBA(renderer, 620, 100, 5, 60, 179, 113, 255);
        }
        else
        {
            filledCircleRGBA(renderer, 620, 100, 5, 191, 191, 191, 255);
        }
    }
}

void mentes(bools* igazak, ints* intek, char* nev)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    SDL_Rect menubg = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &menubg);

    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_Rect uzenet = {WINDOW_WIDTH / 2 - 155, WINDOW_HEIGHT / 2 -30, 310,  60};
    SDL_RenderFillRect(renderer, &uzenet);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_Rect uzenet2 = {WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 25, 300, 50};
    SDL_RenderFillRect(renderer, &uzenet2);

    mentes_beiras(intek, igazak, &uzenet2, nev);

}

void start()
{
    SDL_Surface *start = IMG_Load("start2.png");
    SDL_Texture *start_texture = SDL_CreateTextureFromSurface(renderer, start);
    if (start == NULL)
    {
        SDL_Log("Nem nyithato meg a start kep");
        exit(1);
    }
    SDL_Rect start_img = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderCopy(renderer, start_texture, NULL, &start_img);

    SDL_DestroyTexture(start_texture);
    SDL_FreeSurface(start);

    TTF_Init();
    TTF_Font *font = TTF_OpenFont(FONT, 22);
    if (!font)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Color feher = {255, 165, 0};
    SDL_Surface *felirat;
    SDL_Texture *felirat_t;
    SDL_Rect hova = {0, 0, 0, 0};
    felirat = TTF_RenderUTF8_Blended(font, "Press ENTER to start", feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = WINDOW_WIDTH / 2 - felirat->h / 2 - 85;
    hova.y = WINDOW_HEIGHT / 2 + 60;
    hova.w = felirat->w;
    hova.h = felirat->h;

    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
}

void menu(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter *jatekos)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    SDL_Rect menubg = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &menubg);

    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_Rect uzenet = {WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 70, 300, WINDOW_HEIGHT / 2 - 115};
    SDL_RenderFillRect(renderer, &uzenet);
    if (!igazak->tabella_mut)
    {
        menu_fel(igazak, dbs, intek, ido, jatekos);
    }
}

void game_over(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter* jatekos)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    SDL_Rect menubg = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &menubg);

    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_Rect uzenet = {WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 70, 300, WINDOW_HEIGHT / 2 - 150};
    SDL_RenderFillRect(renderer, &uzenet);
    game_over_fel(igazak, dbs, intek, ido, jatekos);
}

void win(bools *igazak, doubles *dbs, ints *intek, Time *ido, karakter *jatekos)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    SDL_Rect menubg = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &menubg);

    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_Rect uzenet = {WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 70, 300, WINDOW_HEIGHT / 2 - 85};
    SDL_RenderFillRect(renderer, &uzenet);

    SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
    SDL_Rect uzenet2 = {WINDOW_WIDTH / 2 - 130, WINDOW_HEIGHT / 2 - 60, WINDOW_WIDTH / 2 - 140, WINDOW_HEIGHT / 2 - 225};
    SDL_RenderFillRect(renderer, &uzenet2);


    win_fel(igazak, dbs, intek, ido, jatekos);
}

void tabella()
{

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    SDL_Rect menubg = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &menubg);

    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_Rect uzenet = {WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT / 2 - 180, 400, WINDOW_HEIGHT / 2+110};
    SDL_RenderFillRect(renderer, &uzenet);

}

void background(bgr* backg, bgr* backg2)
{
    SDL_Surface *bg = IMG_Load("hatter.png");
    SDL_Texture *bg_texture = SDL_CreateTextureFromSurface(renderer, bg);
    if (bg == NULL)
    {
        SDL_Log("Nem nyithato meg a hatterkepfajl.");
        exit(1);
    }

    SDL_Rect bgimg_dst = {
        (int)backg->x,
        (int)backg->y,
        (int)backg->width,
        (int)backg->height};
    SDL_RenderCopy(renderer, bg_texture, NULL, &bgimg_dst);
    SDL_Surface *bg2;
    bg2 = IMG_Load("hatter.png");
    SDL_Texture *bg_texture2;
    bg_texture2 = SDL_CreateTextureFromSurface(renderer, bg2);

    SDL_Rect bgimg_dst2 = {
        (int)backg2->x,
        (int)backg2->y,
        (int)backg2->width,
        (int)backg2->height};

    SDL_RenderCopy(renderer, bg_texture2, NULL, &bgimg_dst2);
    SDL_DestroyTexture(bg_texture);
    SDL_FreeSurface(bg);
    SDL_DestroyTexture(bg_texture2);
    SDL_FreeSurface(bg2);
}
