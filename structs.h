#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdbool.h>
#include <SDL.h>

//Perc, masodperc tarolasara alkalmas struktura
typedef struct Time
{
    int perc;               //ido
    double masodperc;       //masodperc
}Time;
//A palya pontjainak eltarolasa(kesobbi kitoltesehez kellõ) alkalmas struktura
typedef struct poly
{
    Sint16 polyx[30];       //polygon x koordinatai
    Sint16 polyy[30];       //polygon y koordinatai
} poly;
//intiger tipusu valtozok tarolasa ebben a strukturaban tortenik (minden ami valtozik)
typedef struct ints
{
    int last_frame_time;    //utolso frame ideje
    //eger input eltarolasahoz kello dolgok
    int katt_x;             //kattintas x
    int katt_y;             //kattintas y
    int eger_x;             //kurzor x helyzete
    int eger_y;             //kurzor y helyzete
    //hajtomu hosszahoz kello adatok
    int temp;               //uzemanyag elozo hossza
    int hosz;               //uzemanyag jelenlegi hossza
    //hajtomu kor kozeppontjainak kezdo kozeppontjat meghatarozopontok
    int x;                  //a hajtomu langjanak kezdoallapot x koordinata
    int y;                  //a hajtomu langjanak kezdoallapot y koordinata
    //leszallopaja kijelzesehez szukseges vonal koordinatai (vonalhoz kezdopont, vegpont)
    int le_x1;              //a leszallopont kezdo pont x koordinataja
    int le_y1;              //a leszallopont kezdo pont y koordinataja
    int le_x2;              //a leszallopont veg pont x koordinataja
    int le_y2;              //a leszallopont veg pont y koordinataja
    int leszallo;           //leszallopont EZ EGY INDEX A PONT TOMB PONTJAT IRJA MAJD FELUL
    //pont eltarolasahoz
    int pontszam;           //pontszam
} ints;
//bool tipusu valtozok tarolasa ebben a strukturaban tortenik
typedef struct bools
{
    bool space_up;          //raketa kapcsolas
    bool left;              //balra forog
    bool right;             //jobbra forog
    bool up;                //felfele megy
    bool freez;             //ido megallitasa
    bool menut;             //menu esc mutatasa
    bool menu_mutat;        //menu kirajzolasa
    bool presstostart;      //kezdokepernyo
    bool game_o;            //jatek vege
    bool tabella_mut;       //tabella rajzolasa
    bool winner_mutat;      //gyozelem
    bool game_is_running;   //jatek futtatasa a jatek main loopja
    bool mentes;            //jatekos nev elmentese
    bool beiras;
    bool mar_beirt;
    bool nev_beirva;
    bool szabaditott;
} bools;
//float tipusu valtozok tarolasa ebben a strukturaban tortenik
typedef struct doubles
{
    double karakter_egyenes_tav; //Karakter tavolsaga
    double delta_time;           //Valos ido
    double fuel;                 //Uzemanyag
} doubles;
//a  raketa langjanak kirajzolasahoz kelllo adatok tarolasa itt tortenik(a raketa langja kor alaku)
typedef struct fuel_tomb
{
    double x;                    //kor kozeppont x koordinata
    double y;                    //kor kozeppont y koordinata
    double opicaty;              //kor attetszosege
} fuel_tomb;

//a karakter palya tavolsaghoz szukseges vektorok koordinatainak eltarolasara alkalmas struktura
typedef struct koordinata
{
    double x;                //x koordinata
    double y;                //y koordinata
} koordi;
//a karakter szukseges adatainak tarolasara alkalmas struktura
typedef struct karakter
{
    double x;                //karakter x kordinataja
    double y;                //karakter y kordinataja
    double width;            //karakter szelessege (kep renderhez)
    double height;           //karakter magassaga   (kep renderhez)
    double y_velocity;       //karakter y iranyu gyorsulasa
    double x_velocity;       //karakter x iranyu gyorsulasa
    double rotation;         //karakter forgatasanak szoge
} karakter;

//hatter tulajdonsagainak eltarolasara alkalmas struktura (ketto kepet rendereltetunk, mert loopban a képet mindig toljuk jobbra)
typedef struct bgr
{
    double x;                //hatter x koordinataja
    double y;                //hatter y koordinataja
    double width;            //hatter szelessege
    double height;           //hatter magassaga
} bgr;
//jobb oldali allapot kijelzo adatainak eltarolasara alkalmas struktura
struct display
{
    double x;                //kijelzo x koordinataja
    double y;                //kijelzo y koordinataja
    double width;            //kijelzo szelessege
    double height;           //kijelzo magassaga
} display;

//Láncoltlista
typedef struct ListaElem
{
    char felhasznalo[30];
    int pontszam;
    Time ideje;
    struct ListaElem *kov;
} ListaElem;


#endif // STRUCTS_H_INCLUDED
