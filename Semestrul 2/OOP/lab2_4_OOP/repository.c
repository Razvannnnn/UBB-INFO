#include <malloc.h>
#include <stdio.h>
#include "repository.h"
#include "MyList.h"
#include "domeniu.h"

MyList* creazaLista(){
    MyList* listaOferte = (MyList *) creazaVector();
    return listaOferte;
}

MyList* copylista(MyList* lista) {
    MyList* copy = creazaLista();
    for(int i=0;i<lista->dimensiune;i++) {
        struct Oferta* oferta = getOferta(*lista, i);
        int id = get_id(*oferta);
        int suprafata = get_suprafata(*oferta);
        int pret = get_pret(*oferta);
        char *tip = get_tip(oferta);
        char *adresa = get_adresa(oferta);
        adauga(copy, creareOferta(id,tip,adresa,suprafata,pret));
    }
    return copy;
}

void distrugeLista(MyList* listaOferte){
    for (int i = 0; i < size(listaOferte); i ++)
        distrugeOferta(get(listaOferte, i));
    distruge(listaOferte);
}

void distrugeListaUndo(MyList* undolist) {
    for(int i=0;i< size(undolist);i++) {
        distrugeLista(undolist->elems[i]);
    }
    distruge(undolist);
}

void adaugare_oferta(MyList* listaOferte, struct Oferta oferta){
    int id_oferta = get_id(oferta);
    for (int i = 0; i < size(listaOferte); i ++)
        if (get_id(*((struct Oferta*)get(listaOferte, i))) == id_oferta) {
            return; /// id existent
        }
    adauga(listaOferte, creareOferta(oferta.id, oferta.tip, oferta.adresa, oferta.suprefata, oferta.pret));
}

void stergere_oferta(MyList* listaOferte, int id){
    int poz_stergere = -1;
    for (int i = 0; i < size(listaOferte); i ++)
        if (get_id(*((struct Oferta*)get(listaOferte, i))) == id)
            poz_stergere = i;
    if (poz_stergere == -1) {
        return; /// id inexistent
    }
    free(((struct Oferta*)get(listaOferte, poz_stergere)));
    sterge(listaOferte, poz_stergere);
}

void modificare_oferta(MyList* listaOferte, int id, struct Oferta oferta){
    int poz = -1;
    for (int i = 0; i < size(listaOferte); i ++)
        if (id == get_id(*((struct Oferta*)get(listaOferte, i))))
            poz = i;
    if (poz == -1)
        return; /// id inexistent
    set_id(((struct Oferta*)get(listaOferte, poz)), id);
    set_tip(((struct Oferta*)get(listaOferte, poz)), get_tip(&oferta));
    set_suprafata(((struct Oferta*)get(listaOferte, poz)), get_suprafata(oferta));
    set_adresa(((struct Oferta*)get(listaOferte, poz)), get_adresa(&oferta));
    set_pret(((struct Oferta*)get(listaOferte, poz)), get_pret(oferta));
}

void get_all_oferte(MyList* listaOferte, struct Oferta* oferte_copie, int *dim){
    *dim = size(listaOferte);
    for (int i = 0; i < size(listaOferte); i ++) {
        set_id(&oferte_copie[i], get_id(*((struct Oferta*)(get(listaOferte, i)))));
        set_tip(&oferte_copie[i], get_tip(((struct Oferta*)get(listaOferte, i))));
        set_adresa(&oferte_copie[i], get_adresa(((struct Oferta*)get(listaOferte, i))));
        set_suprafata(&oferte_copie[i], get_suprafata(*((struct Oferta*)get(listaOferte, i))));
        set_pret(&oferte_copie[i], get_pret(*((struct Oferta*)get(listaOferte, i))));
    }
}

void dimensiune(MyList* listaOferte, int *dim){
    *dim = size(listaOferte);
}