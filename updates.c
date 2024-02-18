#include "updates.h"
#include <stdlib.h>

// Az urhajo es a fold kozotti tavolsag merese
void tav(doubles *dbs, karakter* jatekos, SDL_Point* pont_tomb)
{
    //Az urhajo es a buckak kozotti tavolsag szamolasanak gondolatmenete:
    /*Legeloszor meg kell keresunk az a ket pontot amik kozott van jelen pillanatban az urhajo. Ezt egy forciklussal fogjuk megkerestetni a pont_tomb tombbol amit meg a
    setup fuggvenyben generaltattunk le. Ha megtalalta mely ket pont kozott van az urhajo a kovetkezoket kell csinalnunk. Egy ideiglenes koordinata valtozoban fogjuk
    a ket pont koordinatait eltarolni (tempA, tempB). Ezekbol a pontokbol eloszor iranyvektort majd normal vektort csinalunk. Ezekbol mar felirhato az egyenes egyenlete.
    Mar csak azt a pontot kell megkeresnunk amihez a legkozelebb van az urhajonk. Forditott pitagorasz tetellel fogjuk megadni ezt a pontot ket seged ponttal, majd abszolut ertekben fogjuk
    a kesobbiekben vizgsalni az erteket. A ket segedpont a Q és az E pontok. A Q pont y koordinataja megeggyezik a karakter y koordinatajaval, az x koordinataja pedig
    az egyenesen van rajta (amit a ket ponttal adtunk meg), ezt az egyenes egyenletevel es egy kis egyenlet rendezessel szamoljuk ki. Az E pont x koordinataja a karakter
    x koordinatajaval egyezik meg az y koordinatajat pedig az egyenesen van rajta. (fenti modszerrel hatarozzuk meg azt is).
    FONTOS: ha tulsagosan "meredek" az egyenes ezek a szamitasok nem fognak valos vegeredmenyt adni.*/

    koordi tempA, tempB;                        //ideiglenes koordinatak (amik a karakter x koordinatait fogjak majd kozre)
    tempA.x = 0, tempA.y = 600,
    tempB.x = -100, tempB.y = 500;              //ha nem talal ilyen pontot adunk nekik egy kezdoerteket
    for (int i = 0; i < 29; i++)
    {
        if (jatekos->x+(jatekos->width/2) > pont_tomb[i].x && jatekos->x+(jatekos->width/2) < pont_tomb[i + 1].x)   //megkeressuk a ket pontot ami kozott van jelenleg a karakter
        {

            tempA.x = pont_tomb[i].x;           //elmentjuk tempA-t
            tempA.y = pont_tomb[i].y;
            tempB.x = pont_tomb[i + 1].x;       //elmentjuk tempB-t
            tempB.y = pont_tomb[i + 1].y;
        }
    }

        // egyenes iranyvektora
        koordi AB_vektor;
        AB_vektor.x = tempB.x - tempA.x;
        AB_vektor.y = tempB.y - tempA.y;

        // normalvektor
        koordi AB_normal_vektor;
        AB_normal_vektor.x = -AB_vektor.y;
        AB_normal_vektor.y = AB_vektor.x;

        // X0 koordinata keresese
        koordi Q;
        Q.x = (AB_normal_vektor.x * tempA.x + AB_normal_vektor.y * tempA.y - AB_normal_vektor.y * (jatekos->y + jatekos->height / 2)) / AB_normal_vektor.x;
        Q.y = jatekos->y + jatekos->height / 2;


        // Y0 koordinata keresese
        koordi E;
        E.x = jatekos->x + jatekos->width / 2;
        E.y = (AB_normal_vektor.x * tempA.x + AB_normal_vektor.y * tempA.y - AB_normal_vektor.x * (jatekos->x + jatekos->width / 2)) / AB_normal_vektor.y;

        // Megmutatja, hogy melyik ponthoz méri a távolságot a komptól, tesztelesnel nagyon hasznos
        /*-----------------------------------------------------
        filledCircleRGBA(renderer, Q.x, Q.y, 4, 250,0, 0, 255);
        filledCircleRGBA(renderer, E.x, E.y, 4, 250,0, 0, 255);
        filledCircleRGBA(renderer, E.x, Q.y, 4, 250,0, 0, 255);
        SDL_RenderPresent(renderer);
        ------------------------------------------------------*/

        //karakter pont tavolsag forditott pitagorasz tetellel
        dbs->karakter_egyenes_tav = pow((pow((float)fabs(jatekos->x - Q.x), -2.0) + pow((float)fabs(jatekos->y - E.y), -2.0)), -0.5);

}

//a hajtomu reszecskeinek kozeppont koordinatait dinamikus tombe taroljuk el
/*Ha a hajomu be van kapcsolva akkor a kilovello "lang buborekok" hossza folyamatosan no.
 Mivel valtozo hosszusagu ideig lehet bekapcsolni a hajtomuvet ezert a dinamikus tomb
 hasznalata nelkulozhetetlen. */
fuel_tomb* ujmeret_fuel_tomb(int ujhosz, fuel_tomb **uzem)
{

    fuel_tomb *uj_uzem = (fuel_tomb *)malloc(ujhosz * sizeof(fuel_tomb));   //helyet foglalunk a tombnek

    if (uj_uzem == NULL)                                                    //ha nem sikerult a foglalas tegye a kovetkezoket
    {
        SDL_Log("Memoriakezeles hiba");
        exit(1);
    }
    for (int i = 0; i < ujhosz; i++)
    {
        uj_uzem[i]=(*uzem)[i];
        /*uj_uzem[i].x = uzem[i].x;
        uj_uzem[i].y = uzem[i].y;
        uj_uzem[i].opicaty = uzem[i].opicaty;*/        //atmasolja a regi tombbol az ujba a koordinatakat
    }
    free(*uzem);
   *uzem=uj_uzem;
                        //masolas utan felszabaditjuk
                                //majd megkapja az uj tombot
}

//Az urhajo es a forgatasa
/*Eloszor is az urhajo kepet kell megnyitni. Majd belerakjuk egy negyzetbe amit majd a kesobbiekben forgatni is tudunk*/
void figura(karakter* jatekos, ints* intek)
{
    // Figura kepe
    SDL_Surface *image = IMG_Load("babu2.png");                                 //kep megnyitasa
    SDL_Texture *img_texture = SDL_CreateTextureFromSurface(renderer, image);   //texturat csinalunk belole
    if (image == NULL)                                                          //hiba eseten lepjen ki errorral
    {
        SDL_Log("Nem nyithato meg a kepfajl.");
        exit(1);
    }
    if (img_texture == NULL)                                                    //hiba eseten lepjen ki errorral
    {
        SDL_Log("Nem sikerult a texturat letrehozni: %s", SDL_GetError());
        SDL_FreeSurface(image);
        exit(1);
    }
    // Figura negyzete
    SDL_Rect img_dst = {(int)jatekos->x, (int)jatekos->y, (int)jatekos->width, (int)jatekos->height};
    SDL_RenderCopyEx(renderer, img_texture, NULL, &img_dst, jatekos->rotation, NULL, SDL_FLIP_NONE);

    // Hajtomu kezdo allapota
    /*A hajtomu kezdoallapota az a pont ahonnan a reszecske buborekok fognak kilovellni. Bele kell szanolni a forgatast is. A szog radianba van igy el kell osztanunk 57-el*/
    intek->x = jatekos->x + jatekos->width / 2 + cos((jatekos->rotation + 90) / 57.0) * 20;
    intek->y = jatekos->y + jatekos->height / 2 + sin((jatekos->rotation + 90) / 57.0) * 20;

    SDL_DestroyTexture(img_texture);
    SDL_FreeSurface(image);
}

//Idozito
/*Az idozito lesz az ami meri az eltelt idot a jatek elinditasa ota. Ez az eredmeny be fog kerulni a tabellaba (ha belefer a top tizbe)*/
void idozito(Time* ido, doubles* dbs)
{
    ido->masodperc+=1*dbs->delta_time;      //masodpercenkent hozzaadunk egyet
    if((int)ido->masodperc>=59){            //ha eleri az 59-et akkor lenullazuk es a perc erteket megnoveljuk eggyel
        ido->masodperc=0;
        ido->perc+=1;
    }
}

//Frissito fuggvenyunk
/*A jatek menetenek lenyegi resze itt tortenik. Itt hatarozzuk meg a delta time-ot ami a mozgasokert felelos. Ha peldaul azt szeretnenk megadni, hogy az
urhajo 200px/s-al menjen akkor a megfelelo x,y koordinataihoz kell hozzaadni 200*deltatime erteket. A delta time tehat ahhoz kell, hogy a loopban megfelelo
*/
void update(bools *igazak, doubles *dbs, ints *intek, Time* ido, karakter* jatekos, bgr* backg, bgr* backg2, SDL_Point* pont_tomb, fuel_tomb** uzem)
{
    // az eltelt idot masodpercben
    dbs->delta_time = (SDL_GetTicks() - intek->last_frame_time) / 1000.f;
    intek->last_frame_time = SDL_GetTicks();

    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - intek->last_frame_time);
    if (time_to_wait > 0 && time_to_wait < FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }


    //Ido és Pont
    /*a tabella elengedhetetlen elmei lesznek a kesobbiekben*/
    if(!igazak->freez&&igazak->presstostart){
        idozito(ido, dbs);
        intek->pontszam-=1.0*dbs->delta_time;
    }

    // Dinamikus tombje az uzemanyag reszecskeknek
    intek->temp = intek->hosz;
    if (igazak->up && dbs->fuel > 0 && !igazak->freez && !igazak->game_o && igazak->presstostart)
    {
        intek->hosz++;
        ujmeret_fuel_tomb(intek->hosz, uzem);
        jatekos->y_velocity -= cos(jatekos->rotation / 57.0) * 30 * dbs->delta_time;
        jatekos->x_velocity += sin(jatekos->rotation / 57.0) * 30 * dbs->delta_time;

        dbs->fuel -= 10 * dbs->delta_time;
        for(int i=intek->temp; i<intek->hosz; i++){
            (*uzem)[i].x=intek->x;
            (*uzem)[i].y=intek->y;
            (*uzem)[i].opicaty=255;
        }
        intek->temp=intek->hosz;

    }


    if (!igazak->freez)
    {
        for (int i = 0; i < intek->hosz; i++)
        {
            (*uzem)[i].x -= sin(jatekos->rotation / 57.0) * 100 * dbs->delta_time;
            (*uzem)[i].y += cos(jatekos->rotation / 57.0) * 100 * dbs->delta_time;
            (*uzem)[i].opicaty -= 900 * dbs->delta_time;

        }
    }
    if (!igazak->freez)
    {
        jatekos->y += jatekos->y_velocity * dbs->delta_time;
        jatekos->x += jatekos->x_velocity * dbs->delta_time;
    }

    // Jobbra-balra forogjon
    if (igazak->right && !igazak->freez)
    {
        jatekos->rotation += 100 * dbs->delta_time;
    }
    if (igazak->left && !igazak->freez)
    {
        jatekos->rotation -= 100 * dbs->delta_time;
    }

    // A holdnak a sajat gravitacioja meg az urnek
    if (igazak->presstostart && !igazak->freez)
    {
        if (jatekos->y > 200)
        {
            jatekos->y_velocity += 2 * dbs->delta_time;
        }
        else
        {
            jatekos->x_velocity += 2 * dbs->delta_time;
        }
    }
    // Hatter
    if (!igazak->freez)
    {
        backg->x += 15 * dbs->delta_time;
        backg->y = 0;
        backg->width = 800;
        backg->height = 600;
        if (backg->x / 800 > 1)
        {
            backg->x -= 800;
        }
        backg2->x = backg->x - 800;
        backg2->y = 0;
        backg2->width = 800;
        backg2->height = 600;
    }




    // jo leszallasi pont
    tav(dbs, jatekos, pont_tomb);
    if (jatekos->x > pont_tomb[intek->leszallo - 1].x && (jatekos->x + jatekos->width) < pont_tomb[intek->leszallo].x &&
        jatekos->y + jatekos->height >= pont_tomb[intek->leszallo].y && abs(jatekos->x_velocity) <= 10 && abs(jatekos->y_velocity) <= 10
        &&jatekos->rotation<5&&!(dbs->karakter_egyenes_tav<30&&igazak->space_up))
    {
        jatekos->y_velocity = 0;
        jatekos->x_velocity = 0;
        igazak->winner_mutat = true;
        igazak->freez = true;
    }


    //SDL_Log("%lf", dbs->karakter_egyenes_tav);
    if (dbs->karakter_egyenes_tav < 30)
    {
        igazak->game_o = true;
    }
}


