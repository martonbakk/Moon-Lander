#include "texts.h"


void display_fel(doubles *dbs, ints *intek, karakter *jatekos)
{
    TTF_Init();
    TTF_Font *font = TTF_OpenFont(FONT, 22);
    if (!font)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color feher = {255, 255, 255};
    SDL_Surface *felirat;
    SDL_Texture *felirat_t;

    felirat = TTF_RenderUTF8_Blended(font, "Velocity Y", feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    SDL_Rect hova = {730 - felirat->w, 10, felirat->w, felirat->h};
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    char buffer[50];
    sprintf(buffer, "%d", abs(jatekos->y_velocity));
    felirat = TTF_RenderUTF8_Blended(font, buffer, feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 750;
    hova.y = 10;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    felirat = TTF_RenderUTF8_Blended(font, "Velocity X", feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 730 - felirat->w;
    hova.y = 35;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    char buffer2[50];
    sprintf(buffer2, "%d", abs(jatekos->x_velocity));
    felirat = TTF_RenderUTF8_Blended(font, buffer2, feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 750;
    hova.y = 35;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    felirat = TTF_RenderUTF8_Blended(font, "Attitude", feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 730 - felirat->w;
    hova.y = 60;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    char buffer3[50];
    sprintf(buffer3, "%.0lf", 600 - jatekos->y);
    felirat = TTF_RenderUTF8_Blended(font, buffer3, feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 750;
    hova.y = 60;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    felirat = TTF_RenderUTF8_Blended(font, "Fuel", feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 730 - felirat->w;
    hova.y = 85;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);

    char buffer4[50];
    sprintf(buffer4, "%d", abs(dbs->fuel));
    felirat = TTF_RenderUTF8_Blended(font, buffer4, feher);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = 750;
    hova.y = 85;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
    TTF_CloseFont(font);
}

void game_over_fel(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter *jatekos)
{

    TTF_Init();
    TTF_Font *font2 = TTF_OpenFont(FONT, 22);
    if (!font2)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color szin = {255, 255, 255};

    SDL_Surface *felirat2;
    SDL_Texture *felirat_t2;

    felirat2 = TTF_RenderUTF8_Blended(font2, "New Game", szin);
    SDL_Rect hova = {WINDOW_WIDTH / 2 - felirat2->w / 2, WINDOW_HEIGHT / 2 - 60, felirat2->w, felirat2->h};
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 &&
        intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->tabella_mut&&!igazak->mentes&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 &&
        intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        dbs->fuel = 70;
        jatekos->x = WINDOW_WIDTH / 2;
        jatekos->y = 180;
        jatekos->rotation = 0;
        igazak->menut = false;
        igazak->menu_mutat = false;
        igazak->freez = false;
        igazak->up = false;
        igazak->space_up = false;
        jatekos->x_velocity = 0;
        jatekos->y_velocity = 0;
        intek->hosz = 0;
        igazak->game_o = false;
        ido->masodperc=0;
        ido->perc=0;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "Quit", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {

        igazak->game_is_running = false;
    }
    TTF_CloseFont(font2);
}

void menu_fel(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter *jatekos)
{
    TTF_Init();
    TTF_Font *font2 = TTF_OpenFont(FONT, 22);
    if (!font2)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color szin = {255, 255, 255};

    SDL_Surface *felirat2;
    SDL_Texture *felirat_t2;

    felirat2 = TTF_RenderUTF8_Blended(font2, "Menu", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    SDL_Rect hova = {WINDOW_WIDTH / 2 - felirat2->w / 2, WINDOW_HEIGHT / 2 - 60, felirat2->w, felirat2->h};
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);

    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);


    felirat2 = TTF_RenderUTF8_Blended(font2, "Leaderboard", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        igazak->tabella_mut = true;
        intek->katt_x = 0;
        intek->katt_y = 0;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "New Game", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        dbs->fuel = 70;
        jatekos->x = WINDOW_WIDTH / 2;
        jatekos->y = 180;
        jatekos->rotation = 0;
        igazak->menut = false;
        igazak->freez = false;
        igazak->menu_mutat = false;
        igazak->up = false;
        igazak->space_up = false;
        jatekos->x_velocity = 0;
        jatekos->y_velocity = 0;
        intek->hosz = 0;
        ido->masodperc=0;
        ido->perc=0;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "Resume", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->tabella_mut&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        igazak->freez = false;
        igazak->menut = false;
        igazak->menu_mutat = false;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "Quit", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->tabella_mut&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        igazak->game_is_running = false;
    }
    TTF_CloseFont(font2);
}

void win_fel(bools *igazak, doubles *dbs, ints *intek, Time *ido, karakter *jatekos)
{
    TTF_Init();
    TTF_Font *font2 = TTF_OpenFont(FONT, 22);
    if (!font2)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color szin = {255, 255, 255};

    SDL_Surface *felirat2;
    SDL_Texture *felirat_t2;

    felirat2 = TTF_RenderUTF8_Blended(font2, "You Win", szin);
    SDL_Rect hova = {WINDOW_WIDTH / 2 - felirat2->w / 2, WINDOW_HEIGHT / 2 - 55, felirat2->w, felirat2->h};

    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;

    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);

    char buffer[50];
    sprintf(buffer, "Your time: %02d:%02.0lf", ido->perc, ido->masodperc);
    felirat2 = TTF_RenderUTF8_Blended(font2, buffer, szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);


    felirat2 = TTF_RenderUTF8_Blended(font2, "Leaderboard", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 40;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->mentes&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->mentes&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        igazak->tabella_mut = true;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "New Game", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->mar_beirt&&!igazak->mentes&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->mar_beirt&&!igazak->mentes&&!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h && !igazak->tabella_mut)
    {
        dbs->fuel = 70;
        jatekos->x = WINDOW_WIDTH / 2;
        jatekos->y = 180;
        jatekos->rotation = 0;
        jatekos->x_velocity = 0;
        jatekos->y_velocity = 0;
        intek->hosz = 0;
        igazak->game_o = false;
        igazak->winner_mutat = false;
        igazak->menut = false;
        igazak->menu_mutat = false;
        igazak->freez = false;
        igazak->up = false;
        igazak->space_up = false;
        igazak->mar_beirt=false;
        ido->masodperc=0;
        ido->perc=0;
    }

    felirat2 = TTF_RenderUTF8_Blended(font2, "Save", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->mar_beirt&&!igazak->mentes&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->mar_beirt&&!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h && !igazak->tabella_mut)
    {
        igazak->mentes = true;
        igazak->beiras=true;
    }
    felirat2 = TTF_RenderUTF8_Blended(font2, "Quit", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (!igazak->mentes&&intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 && intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (!igazak->mentes&&!igazak->tabella_mut&&intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 && intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h && !igazak->tabella_mut)
    {
        igazak->game_is_running = false;
    }
    TTF_CloseFont(font2);
}

void tabella_fel(bools *igazak, ints *intek, ListaElem **eleje)
{
    TTF_Init();
    TTF_Font *font2 = TTF_OpenFont(FONT, 22);
    if (!font2)
    {
        SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color szin = {255, 255, 255};






    SDL_Surface *felirat2;
    SDL_Texture *felirat_t2;
    felirat2 = TTF_RenderUTF8_Blended(font2, "Top 10 Player", szin);
    SDL_Rect hova = {WINDOW_WIDTH / 2 - felirat2->w / 2, WINDOW_HEIGHT / 2 - 200, felirat2->w, felirat2->h + 40};
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y += 32;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);

    rendezes(eleje);
    int db=0;
    if(eleje!=NULL){

    char buffer[300];
    buffer[0]='\0';
    char buffer2[300];
    buffer2[0]='\0';
    char buffer3[300];
    buffer3[0]='\0';
    ListaElem *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(db<10){
        strcat(buffer, mozgo->felhasznalo);

        char pnt[6];
        sprintf(pnt, "%dpt", mozgo->pontszam);
        int pnt_l=strlen(pnt);
        pnt[pnt_l]='\0';
        strcat(buffer2, pnt);
        strcat(buffer2, "\n");

        char id[10];
        sprintf(id, "%02d:%02.0lf ",mozgo->ideje.perc, mozgo->ideje.masodperc);
        int id_l=strlen(id);
        id[id_l]='\0';
        strcat(buffer3,  id);
        strcat(buffer, "\n");
        }
        db++;
    }
    felirat2 = TTF_RenderUTF8_Blended_Wrapped(font2, buffer, szin, 300);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    SDL_Rect hova2 = {WINDOW_WIDTH / 2 - 170, WINDOW_HEIGHT / 2 - 120, felirat2->w<300?felirat2->w:300, felirat2->h};
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova2);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);

    felirat2 = TTF_RenderUTF8_Blended_Wrapped(font2, buffer2, szin, 60);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    SDL_Rect hova3 = {WINDOW_WIDTH / 2-30 , WINDOW_HEIGHT / 2 - 120, felirat2->w, felirat2->h};
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova3);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);

    felirat2 = TTF_RenderUTF8_Blended_Wrapped(font2, buffer3, szin, 70);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    SDL_Rect hova4 = {WINDOW_WIDTH / 2+100 , WINDOW_HEIGHT / 2 - 120, felirat2->w, felirat2->h};
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova4);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    }





    felirat2 = TTF_RenderUTF8_Blended(font2, "Back", szin);
    felirat_t2 = SDL_CreateTextureFromSurface(renderer, felirat2);
    hova.x = WINDOW_WIDTH / 2 - felirat2->w / 2;
    hova.y = 490;
    hova.w = felirat2->w;
    hova.h = felirat2->h;
    if (intek->eger_x >= hova.x - 40 && intek->eger_x <= hova.w + hova.x + 40 &&
        intek->eger_y >= hova.y && intek->eger_y <= hova.h + hova.y)
    {
        roundedBoxRGBA(renderer, hova.x - 40, hova.y, hova.w + hova.x + 40, hova.h + hova.y, 5, 128, 128, 128, 255);
    }
    SDL_RenderCopy(renderer, felirat_t2, NULL, &hova);
    SDL_FreeSurface(felirat2);
    SDL_DestroyTexture(felirat_t2);
    if (intek->katt_x >= hova.x - 40 && intek->katt_x <= hova.w + hova.x + 40 &&
        intek->katt_y >= hova.y && intek->katt_y <= hova.y + hova.h)
    {
        igazak->tabella_mut = false;
    }
    TTF_CloseFont(font2);
}

void mentes_beiras(ints* intek, bools* igazak, SDL_Rect* uzenet, char* nev)
{
    int maxw=uzenet->w;
    int maxh=uzenet->h;
    int w=0;
        if(nev[0]!='\0'){
        TTF_Init();
            TTF_Font *font = TTF_OpenFont(FONT, 30);
            if (!font)
            {
                SDL_Log("Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
                exit(1);
            }
            SDL_Color sarga = {255, 165, 0};
            SDL_Surface* felirat=TTF_RenderUTF8_Blended(font, nev, sarga);
            SDL_Texture *felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
            SDL_Rect cel = { uzenet->x+5, uzenet->y+5, felirat->w+10 < maxw ? felirat->w : maxw-10,
            felirat->h+5 < maxh ? felirat->h : maxh };
            SDL_RenderCopy(renderer, felirat_t, NULL, &cel);
            SDL_FreeSurface(felirat);
            SDL_DestroyTexture(felirat_t);

            w = cel.w;
        }else{
            w=0;
        }

        if (w < maxw) {
            vlineRGBA(renderer, uzenet->x + w + 2, uzenet->y + 5, uzenet->y + uzenet->h - 5, 255,255,255, 192);
        }
        SDL_RenderPresent(renderer);
    }
