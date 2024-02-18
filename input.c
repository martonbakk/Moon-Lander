#include "input.h"
#include <string.h>

/*Ebben a fuggvenyben figyeljuk/mentjuk az interakciokat */
void processe_input(bools *igazak, ints *intek, char* nev)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:                           //eger lenyomva
        if (event.button.button == SDL_BUTTON_LEFT)     //baleger gomb
        {
            intek->katt_x = event.button.x;             //katt X koordinataja
            intek->katt_y = event.button.y;             //katt Y koordinataja
        }
        break;
    case SDL_MOUSEBUTTONUP:                             //eger felengedve
        intek->katt_x = 0;                              //katt X koordinataja nullazas
        intek->katt_y = 0;                              //katt Y koordinataja nullazas
        break;
    case SDL_MOUSEMOTION:                               //kurzor aktualis helyzete
        intek->eger_x = event.motion.x;                 //helyzet X mentese
        intek->eger_y = event.motion.y;                 //helyzet Y mentese
        break;
    case SDL_KEYDOWN:                                   //billentyu lenyomva
        if (event.key.keysym.sym == SDLK_RETURN)
        {
            igazak->presstostart = true;                //enter a jatek elinditasahoz
        }
        if (event.key.keysym.sym == SDLK_ESCAPE &&
        !igazak->menut && igazak->presstostart &&
        !igazak->game_o && !igazak->winner_mutat)       //escape-re mikor reagaljon
        {
            igazak->menut = true;                       //menut megnyitasa escapre
            igazak->freez = true;                       //menu megnyitasa escapre
            igazak->menu_mutat = true;
        }
        else if (event.key.keysym.sym == SDLK_ESCAPE && igazak->menut && !igazak->tabella_mut) //ha megegyszer megnyomja az escapet akkor tunjon el
        {
            igazak->menut = false;
            igazak->freez = false;
            igazak->menu_mutat = false;
        }
        else if (event.key.keysym.sym == SDLK_LEFT)     //balra nyil lenyomasa-> forogas balra engedelyezze
        {
            igazak->left = true;
        }
        else if (event.key.keysym.sym == SDLK_RIGHT)    //jobra nyil lenyomasa-> forgas jobra engedelyezze
        {
            igazak->right = true;
        }
        else if (event.key.keysym.sym == SDLK_SPACE)    //hajtomu bekapcsol ha egyszer lenyomja a spacet
        {
            if (!igazak->space_up)
            {
                igazak->up = true;                      //ha egyszer lenyomta akkor hajtomu bekapcsolas
                igazak->space_up = true;
            }
            else
            {
                igazak->up = false;                     //ha megegyszer lenyomta akkor hajtomu kikapcsolas
                igazak->space_up = false;
            }
        }
        if (event.key.keysym.sym == SDLK_RETURN && igazak->mentes) {
                igazak->mentes = false;
                size_t len = strlen(nev);
                nev[len+1]='\0';
                igazak->beiras=true;
                igazak->mar_beirt=true;
                igazak->nev_beirva=true;
        }
        if(event.key.keysym.sym == SDLK_ESCAPE && igazak->mentes){
                igazak->mentes=false;
                nev[0]='\0';
        }
        else if (event.key.keysym.sym == SDLK_BACKSPACE && igazak->mentes) {
                // Backspace lenyomására karakter törlése a szövegbõl
                size_t len = strlen(nev);
                if (len > 0) {
                    if((nev[len-1]&0x80)==0x00){
                        nev[len-1]=0x00;
                        break;
                    }
                    if((nev[len-1]&0xC0)==0x80){
                        nev[len-1]=0x00;
                        break;
                    }
                    if((nev[len-1]&0xC0)==0xC0){
                        nev[len-1]=0x00;
                        break;
                    }
                }
                nev[len+1]='\0';
            }
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_LEFT)          //ha fel van engedve a balra nyil ne forogjon
        {
            igazak->left = false;
        }
        else if (event.key.keysym.sym == SDLK_RIGHT)    //ha fel van engedve a jobra nyil ne forogjon
        {
            igazak->right = false;
        }
        break;
    case SDL_TEXTINPUT:  // Szövegbevitel eseménye
            if (igazak->mentes&&strlen(nev)+strlen(event.text.text)<30) {

                  strcat(nev, event.text.text); // Hozzáfûzi az új szöveget a már meglévõhöz
            }
        break;
    }
}
