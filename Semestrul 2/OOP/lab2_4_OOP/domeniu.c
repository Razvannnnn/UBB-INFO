#include <string.h>
#include <malloc.h>
#include "domeniu.h"


int get_id(struct Oferta oferta){
    return oferta.id;
}

char *get_tip(struct Oferta* oferta){
    return oferta->tip;
}

char *get_adresa(struct Oferta* oferta){
    return oferta->adresa;
}

int get_suprafata(struct Oferta oferta){
    return oferta.suprefata;
}

int get_pret(struct Oferta oferta){
    return oferta.pret;
}

void set_id(struct Oferta* oferta, int id){
    oferta->id = id;
}

void set_tip(struct Oferta* oferta, char tip[]){
    strcpy(oferta->tip, tip);
}

void set_adresa(struct Oferta* oferta, char adresa[]){
    strcpy(oferta->adresa, adresa);
}

void set_suprafata(struct Oferta* oferta, int suprafata){
    oferta->suprefata = suprafata;
}

void set_pret(struct Oferta* oferta, int pret){
    oferta->pret = pret;
}

struct Oferta* creareOferta(int id, char tip[], char adresa[], int suprafata, int pret){
    struct Oferta* oferta = (struct Oferta*)malloc(sizeof(struct Oferta));
    oferta->id = id;
    strcpy(oferta->tip, tip);
    strcpy(oferta->adresa, adresa);
    oferta->suprefata = suprafata;
    oferta->pret = pret;
    return oferta;
}

void distrugeOferta(struct Oferta* oferta) {
    free(oferta);
}
