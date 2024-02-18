#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "structs.h"
#include <stdio.h>

void lista_felszabaditas(ListaElem *eleje);
ListaElem *lista_elejere_beszur(ListaElem *eleje, char* nev, int pontszam, Time ido);
void fajlbol_beolvas(FILE* fajl, ListaElem** eleje);

#endif // LISTA_H_INCLUDED
