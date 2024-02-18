#include "save.h"

void save(ListaElem **eleje, char* nev, ints* intek, Time ido, bools* igazak)
{
    if(igazak->nev_beirva){
    *eleje=lista_elejere_beszur(*eleje, nev, intek->pontszam, ido);
    FILE* mentes=fopen("mentes.txt", "w");
    if(mentes!=NULL){
        fajlba_iras(mentes, *eleje);
    }
    fclose(mentes);
    igazak->nev_beirva=false;
    igazak->mar_beirt=true;
    }
}
