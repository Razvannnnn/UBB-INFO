#ifndef LAB2_4_OOP_SERVICE_H
#define LAB2_4_OOP_SERVICE_H

#include "domeniu.h"
#include <string.h>
#include "validare.h"
#include "repository.h"

void adaugareOferte(MyList *repo, MyList* undolist, int id, char tip[], char adresa[], int suprafata, int pret);
/**
 * functia creaza obiectul ofera si il adauga in lista
 * */

void modificareOferta(MyList *repo, MyList* undolist, int id, char tip[], char adresa[], int suprafata, int pret);
/**
 * functia modica oferta in functie de id
 * */

void stergereOferta(MyList *repo, MyList* undolist, int id);
/**
 * functia sterge obictul oferta in functie de id
 * */

void ordonareBubble(MyList *repo, struct Oferta* oferte, int (*verificare)());
void odonareOferteDupaPretTip(MyList *repo, struct Oferta* oferte, int (*verificare)());
/**
 * functia ordoneaza (crescator/descrescator) obiectele
 * oferte dupa pret si dupa tip
 * daca cresc = 1 - se va ordona crecator
 * daca cressc = 0 - se va ordona descrescator
 * */

void filtrareNoua(MyList *repo, struct Oferta* oferte, int *l, int pret);
void filtrareDupaUnCriteriu(MyList *repo, struct Oferta* oferte, int *l, int criteriu, int suprafata, char tip[], int pret);
/**
 * functia filtreaza ofertele dupa un criteriu
 *
 * */

void getAllOferte(MyList *repo, struct Oferta* oferte_copie, int *dim);
/**
 * functia returneaza toate ofertele
 * */

void Dim(MyList *repo, int *dim);
/**
 * functia returneaza dimensiunea vectorului
 * */

int sort_cresc_verif(struct Oferta ofertai, struct Oferta ofertaj);

int sort_descresc_verif(struct Oferta ofertai, struct Oferta ofertaj);

#endif //LAB2_4_OOP_SERVICE_H
