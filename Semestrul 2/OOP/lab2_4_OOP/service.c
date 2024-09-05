#include <malloc.h>
#include "service.h"

struct Oferta creazaObiect(int id, char tip[], char adresa[], int suprafata, int pret){
    struct Oferta oferta;
    oferta.id = id;
    strcpy(oferta.tip, tip);
    strcpy(oferta.adresa, adresa);
    oferta.suprefata = suprafata;
    oferta.pret = pret;
    return oferta;
}

void adaugareOferte(MyList *repo, MyList* undolist, int id, char tip[], char adresa[], int suprafata, int pret){
    struct Oferta oferta = creazaObiect(id, tip, adresa, suprafata, pret);
    char erori[50];
    validare_oferta(oferta, erori);
    if (strlen(erori) > 0)
        return;
    adauga(undolist, copylista(repo));
    adaugare_oferta(repo, oferta);
}

void modificareOferta(MyList *repo, MyList* undolist, int id, char tip[], char adresa[], int suprafata, int pret){
    struct Oferta oferta = creazaObiect(id, tip, adresa, suprafata, pret);
    char erori[50];
    validare_oferta(oferta, erori);
    if (strlen(erori) > 0)
        return;
    adauga(undolist, copylista(repo));
    modificare_oferta(repo, id, oferta);
}

void stergereOferta(MyList *repo, MyList* undolist, int id){
    adauga(undolist, copylista(repo));
    stergere_oferta(repo, id);
}

int sort_cresc_verif(struct Oferta ofertai, struct Oferta ofertaj){
    if (ofertai.pret == ofertaj.pret)
        return strcmp(ofertai.tip, ofertaj.tip) > 0;
    return ofertai.pret > ofertaj.pret;
}

int sort_descresc_verif(struct Oferta ofertai, struct Oferta ofertaj){
    if (ofertai.pret == ofertaj.pret)
        return strcmp(ofertai.tip, ofertaj.tip) < 0;
    return ofertai.pret < ofertaj.pret;
}


void odonareOferteDupaPretTip(MyList *repo, struct Oferta* oferte, int (*verificare)()){
    int dim;
    dimensiune(repo, &dim);
    get_all_oferte(repo, oferte, &dim);

    for (int i = 0; i < dim - 1 ; i ++)
        for (int j = i + 1; j < dim; j ++)
            if (verificare(oferte[i], oferte[j])){
                struct Oferta aux = oferte[i];
                oferte[i] = oferte[j];
                oferte[j] = aux;
            }
}

void ordonareBubble(MyList *repo, struct Oferta* oferte, int (*verificare)()) {
    int dim;
    dimensiune(repo, &dim);
    get_all_oferte(repo, oferte, &dim);
    int ok = 1;
    do {
        ok=0;
        for(int i=0;i<dim - 1;i++) {
            if(verificare(oferte[i], oferte[i+1])) {
                struct Oferta aux = oferte[i];
                oferte[i] = oferte[i+1];
                oferte[i+1] = aux;
                ok=1;
            }
        }
    } while (ok);
}

void copiere_oferta(struct Oferta* destinatie, struct Oferta* oferta){
    destinatie->id = oferta->id;
    strcpy(destinatie->tip, oferta->tip);
    strcpy(destinatie->adresa, oferta->adresa);
    destinatie->suprefata = oferta->suprefata;
    destinatie->pret = oferta->pret;
}

void filtrareDupaUnCriteriu(MyList *repo, struct Oferta* oferte, int *l, int criteriu, int suprafata, char tip[], int pret){
    int dim;
    dimensiune(repo, &dim);
    *l = 0;
    struct Oferta* lista = (struct Oferta*) malloc(dim * sizeof(struct  Oferta));
    get_all_oferte(repo, lista, &dim);
    for (int i = 0; i < dim; i ++){
        if (criteriu == 1) {
            if (get_suprafata(lista[i]) == suprafata)
                copiere_oferta(&oferte[*l], &lista[i]), *l += 1;
        }
        else if (criteriu == 2) {
            if (strcmp(get_tip(&lista[i]), tip) == 0)
                copiere_oferta(&oferte[*l], &lista[i]), *l += 1;
        }
        else if (criteriu == 3){
            if (get_pret(lista[i]) == pret)
                copiere_oferta(&oferte[*l], &lista[i]), *l += 1;
        }
    }

    free(lista);
}

void filtrareNoua(MyList *repo, struct Oferta* oferte, int *l, int pret) {
    int dim;
    dimensiune(repo, &dim);
    *l = 0;
    struct Oferta* lista = (struct Oferta*) malloc(dim * sizeof(struct Oferta));
    get_all_oferte(repo, lista, &dim);
    for(int i=0;i<dim;i++) {
        if(get_pret(lista[i]) >= pret) {
            copiere_oferta(&oferte[*l], &lista[i]);
            *l += 1;
        }
    }
    free(lista);
}


void getAllOferte(MyList *repo, struct Oferta* oferte_copie, int *dim){
    get_all_oferte(repo, oferte_copie, dim);
}

void Dim(MyList *repo, int *dim){
    dimensiune(repo, dim);
}

