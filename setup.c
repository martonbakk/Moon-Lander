#include "setup.h"

void setup(bools *igazak, doubles *dbs, ints *intek, poly *poligon, Time* ido, karakter *jatekos, char* nev, ListaElem **eleje, SDL_Point* pont_tomb, fuel_tomb** uzem){

    FILE* mentes1=fopen("mentes.txt", "r");
    if(mentes1!=NULL){
        fajlbol_beolvas(mentes1, eleje);
    }
    fclose(mentes1);

    //logikai valtozok kezdoertekei
    igazak->space_up = false;
    igazak->left = false;
    igazak->right = false;
    igazak->up = false;
    igazak->freez = false;
    igazak->menut = false;
    igazak->menu_mutat = false;
    igazak->presstostart = false;
    igazak->game_o = false;
    igazak->tabella_mut = false;
    igazak->winner_mutat = false;
    igazak->mentes=false;
    igazak->beiras=false;
    igazak->mar_beirt=false;
    igazak->nev_beirva=false;
    igazak->szabaditott=false;
    //floatok kezdoertekei
    dbs->delta_time = 0;
    dbs->fuel = 0;
    dbs->karakter_egyenes_tav = 0;
    //intigerek kezdoertekei
    intek->last_frame_time = 0;
    intek->leszallo = 0;
    intek->katt_x = 0;
    intek->katt_y = 0;
    intek->eger_x = 0;
    intek->eger_y = 0;
    intek->temp = 1;
    intek->hosz = 1;
    intek->pontszam = 1000;
    //Time kezdoertekei
    ido->perc=0;
    ido->masodperc=0;

    // Hajtomu korok dinamikus tomb
    *uzem = (fuel_tomb *)malloc(sizeof(fuel_tomb) * 2);

    // karakter kezdoallapota
    jatekos->x = 400 - 20;
    jatekos->y = 200 - 20;
    jatekos->width = 40;
    jatekos->height = 40;

    // jobb fenti sarok allapotkijelzo
    display.x = 600;
    display.y = 0;
    display.width = 250;
    display.height = 120;

    nev[0]='\0';
    // palya legeneralasa
    /*
    A palya legeneralasa a kovetkezo keppen nez ki:
    -A pont_tomb tipusu tomb x és y részeiben tároljuk el az egyeneseket osszekoto pontokat (Az egyeneseket majd a rendererbe rajzoltatjuk ki)
    -A poligon tomb a palya vonala alatti resz kitoltesehez kello tomb ami szinten pontokat tartalmaz ami alapjan ki fogja a rendererbe tolteni a teret
    A palya legeneralasat randomszammal oldjuk meg. Ha páros a randomszámunk akkor felfele megy, ha páratlan lefele fog menni. A randomszámunk maximum
    erteknek 24 vehet fel, minimum pedig 0-at. Mindig az elozo pont y koordinatajahoz adjuk, vagy vonjuk ki a random szam erteket. A pontok kozott
    fix 30 pontos tavolsag van, hogy fixen vegig erjen a vonal a kepernyo szeleig. Fontos, hogy a palya pontjai nem lehetnek 100 pontnal melyebben és 300 pontnal
    magasabban. FONTOS: A képernyõ teteje a y=0 pontban van, a képernyõ legalja a 600 pontban van. Ezek a pontok fixek.
    */
    for(int i=0; i<30; i++){    //Pont tomb kinullazasa
        pont_tomb[i].x=0;
        pont_tomb[i].y=0;
    }
    int pontok = 30;            //Mennyi pontot szeretnenk
    pont_tomb[0].x = 0;         //Kezdoerteket kell adni, hogy a kitoltes megfelelo legyen a 0. pontban X
    pont_tomb[0].y = 600;       //Kezdoerteket kell adni, hogy a kitoltes megfelelo legyen a 0. pontban Y
    poligon->polyx[0] = 0;      //Osszhangba hozzuk az egyenes 0. pontjaval X
    poligon->polyy[0] = 600;    //Osszhangba hozzuk az egyenes 0. pontjaval Y
    pont_tomb[1].x = 0;         //Kezdoerteket kell adni, hogy a kitoltes megfelelo legyen a 1. pontban X
    pont_tomb[1].y = 500;       //Kezdoerteket kell adni, hogy a kitoltes megfelelo legyen a 1. pontban Y (megadtuk, hogy milyen magasrol induljon a palya legeneralasa)
    poligon->polyx[1] = 0;      //Osszhangba hozzuk az egyenes 1. pontjaval
    poligon->polyy[1] = 500;    //Osszhangba hozzuk az egyenes 1. pontjaval
    for (int i = 2; i < pontok; i++)
    {
        int randomszam = rand();                                    //randomszam
        int ossz=randomszam%25;                                     //osszben eltaroljuk a 25-os maradekat igy maxixmum 24 minimum 0 lesz az erteke
        //Ha nagyon tag intervallumot adunk az ossz-nek a karakter palya tavolsag kiszamolasnal fellephetnek problemak. Maximum 35 lehet ez a szam
         pont_tomb[i].x += pont_tomb[i - 1].x + 30;                 //konstans hozzaad 30-at az elozo x-koordinatahoz
         if(ossz%2==0&&pont_tomb[i-1].y-ossz>=WINDOW_HEIGHT-300){
            pont_tomb[i].y = pont_tomb[i-1].y-ossz;                 //elozo pont magassagat noveli ossz ertekevel
         }
         else if(ossz%2==1&&pont_tomb[i-1].y+ossz<=WINDOW_HEIGHT-100)
         {
            pont_tomb[i].y = pont_tomb[i-1].y+ossz;                 //elozo pont magassagat csokkenti ossz ertekevel
         }
         else{
            pont_tomb[i].y = pont_tomb[i-1].y;                      //marad ugyan az a magassaga ha elerte valamelyik hatarvonalat
         }

        poligon->polyx[i] = pont_tomb[i].x;     //polygonok x pontjait osszhangba hozzuk az egyenes pontjaival
        poligon->polyy[i] = pont_tomb[i].y;     //polygonok x pontjait osszhangba hozzuk az egyenes pontjaival
    }
    poligon->polyy[29] = 600;       //A megfelelõ rendereleshez 0 ra kell allitani a polygon utolso pontjat
    pont_tomb[29].y = 0;            //Osszhangba hozzuk vele az egyenes koordinatajat

    // Uzemanyag
    dbs->fuel = 70;

    // Biztos leszallas
    /*
    Ahhoz, hogy biztos leszallasi pontot kapjunk a jatekban az elozo egyenesek valamely ket pontjat felul kell irni. Azt, hogy melyek lesznek ezek
    a pontok random szammal dontjuk el. A random szam 27-es maradeka fogja megadni, hogy melyik pontot es elotte levo pontot fogjuk felul irni.
    Mivel az elso ketto pont a palya kirenderelesehez kello 0 (0, 600) és 1(0, 500) pontokban vannak így az elsõ két koordinata nem lesz alkalmas erre.
    A 3 pont  (pont_tomb[2]) koordinattol "generaltatunk" palyat ezert ha a randomszam 1-nel kisebb a leszallo koordinatajat megvaltoztatjuk haromra
    Itt a randomszam a tomb indexekent kezelendo
    */
    int rndm=rand()%27;                 //randomszam maradeka
    intek->leszallo = rndm;             //leszallo pontnak is atadjuk, hogy kesobbiekben tudjuk vizsgalni, hogy jo helyre szallt-e le az urhajo
    if (intek->leszallo <= 1)           //feltetel a megfelelo indexhez
    {
        intek->leszallo = 3;
    }
    pont_tomb[intek->leszallo].x = pont_tomb[intek->leszallo - 1].x + 60;       //60 szeles leszallopajat csinalunk
    pont_tomb[intek->leszallo].y = pont_tomb[intek->leszallo - 1].y;            //egy magassagba hozzuk
    poligon->polyx[intek->leszallo] = pont_tomb[intek->leszallo - 1].x + 60;    //szinkronizaljuk a vonallal
    poligon->polyy[intek->leszallo] = poligon->polyy[intek->leszallo - 1];      //szinkronizaljuk a vonallal

    pont_tomb[intek->leszallo + 1].y = pont_tomb[intek->leszallo].y ;       //a leszallopalya szeleinek simitasa
    poligon->polyy[intek->leszallo + 1] = pont_tomb[intek->leszallo].y ;    //osszhanga hozas az egyenessel

    intek->le_x1 = pont_tomb[intek->leszallo - 1].x + 5;       //Az elso leszallo vonal X koordinatajanak meghatarozasa
    intek->le_y1 = pont_tomb[intek->leszallo - 1].y + 5;       //Az elso leszallo vonal Y koordinatajanak meghatarozasa
    intek->le_x2 = pont_tomb[intek->leszallo].x - 5;           //A masodik leszallo vonal X koordinatajanak meghatarozasa
    intek->le_y2 = pont_tomb[intek->leszallo].y + 5;           //A masodik leszallo vonal Y koordinatajanak meghatarozasa
}

