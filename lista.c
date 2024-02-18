#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>


//Lista felszabadítása
void lista_felszabaditas(ListaElem *eleje)
{
    SDL_Log("Lista felszabaditas");
    ListaElem *mozgo = eleje;
    while (mozgo != NULL)
    {
        ListaElem *kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }

}

//Lista elejere beszurja
ListaElem *lista_elejere_beszur(ListaElem *eleje, char* nev, int pontszam, Time ido)
{
    SDL_Log("Lista elejere beszur");

    for(int i=0; nev[i]!='\0'; i++){
        if(nev[i]==' '){
            nev[i]='_';
        }
    }

    ListaElem *uj;
    uj = (ListaElem *)malloc(sizeof(ListaElem));
    if (uj == NULL) {
        printf("Hiba a memoriafoglalaskor");
        exit(1);
    }

    if (uj->felhasznalo == NULL) {
        free(uj);
        printf("Hiba a memoriafoglalaskor");
        exit(1);
    }
    strcpy(uj->felhasznalo, nev);
    uj->pontszam=pontszam;
    uj->ideje=ido;

    uj->kov = eleje;
    eleje=uj;

    return eleje;
}

//beolvasas
void fajlbol_beolvas(FILE* fajl, ListaElem** eleje){
    SDL_Log("Beolvasas");
    char nev[30];
    int pont, perc;
    double masodperc;
    if(fscanf(fajl, "%29s %d %d:%lf\n", nev, &pont, &perc, &masodperc)!=4){
        return;
        SDL_Log("Beolvasas vege");
    }
    Time ido;
    ido.perc=perc;
    ido.masodperc=masodperc;
    *eleje=lista_elejere_beszur(*eleje,  nev, pont, ido);
    fajlbol_beolvas(fajl, eleje);
}

void fajlba_iras(FILE* mentes, ListaElem *eleje) {
    SDL_Log("Faljba iras");
    if (eleje == NULL) {
        return;
        SDL_Log("Faljba iras vege");
    }
    fajlba_iras(mentes, eleje->kov);
    fprintf(mentes,"%s %d %d:%lf\n", eleje->felhasznalo, eleje->pontszam, eleje->ideje.perc, eleje->ideje.masodperc);
}

//Rendezzuk a fajlt
void rendezes(ListaElem** eleje){
    SDL_Log("Rendezes");
    ListaElem* ptr;
    ListaElem* lptr=NULL;
    int swp;
    if(eleje==NULL){
        return;
    }
    do{
        swp=0;
        ptr=eleje;

        while (ptr->kov!=lptr)
        {
            if(ptr->pontszam<ptr->kov->pontszam){
                // Csere a pontszámok között
                int temp_pont = ptr->pontszam;
                ptr->pontszam = ptr->kov->pontszam;
                ptr->kov->pontszam = temp_pont;

                // Csere a felhasználók között
                char temp_felhasznalo[30];
                strcpy(temp_felhasznalo, ptr->felhasznalo);
                strcpy(ptr->felhasznalo, ptr->kov->felhasznalo);
                strcpy(ptr->kov->felhasznalo, temp_felhasznalo);


                // Csere az idõpontok között
                Time temp_ido = ptr->ideje;
                ptr->ideje = ptr->kov->ideje;
                ptr->kov->ideje = temp_ido;

                swp=1;
            }
            if (ptr->pontszam==ptr->kov->pontszam&&(ptr->ideje.perc>ptr->kov->ideje.perc||
            (ptr->ideje.perc==ptr->kov->ideje.perc&&
            ptr->ideje.masodperc>ptr->kov->ideje.masodperc)))
            {
                // Csere a pontszámok között
                int temp_pont = ptr->pontszam;
                ptr->pontszam = ptr->kov->pontszam;
                ptr->kov->pontszam = temp_pont;

                // Csere a felhasználók között
                char temp_felhasznalo[30];
                strcpy(temp_felhasznalo, ptr->felhasznalo);
                strcpy(ptr->felhasznalo, ptr->kov->felhasznalo);
                strcpy(ptr->kov->felhasznalo, temp_felhasznalo);

                // Csere az idõpontok között
                Time temp_ido = ptr->ideje;
                ptr->ideje = ptr->kov->ideje;
                ptr->kov->ideje = temp_ido;

                swp=1;
            }

            ptr=ptr->kov;
        }
        lptr=ptr;
    }while(swp);
}
