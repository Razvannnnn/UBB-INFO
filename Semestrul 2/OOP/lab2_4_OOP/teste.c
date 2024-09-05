#include "teste.h"
#include "domeniu.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "repository.h"
#include "validare.h"
#include "service.h"
#include "MyList.h"

void teste_domeniu(){
    struct Oferta oferta[2];

    set_id(&oferta[0], 1);
    set_tip(&oferta[0], "apartament");
    set_adresa(&oferta[0], "Cluj");
    set_suprafata(&oferta[0], 400);
    set_pret(&oferta[0], 30123);

    assert(get_id(oferta[0]) == 1);
    assert(strcmp(get_tip(&oferta[0]), "apartament") == 0);
    assert(strcmp(get_adresa(&oferta[0]), "Cluj") == 0);
    assert(get_suprafata(oferta[0]) == 400);
    assert(get_pret(oferta[0]) == 30123);
}

void teste_repository(){
    MyList *repo = creazaLista();
    struct Oferta oferta = {1, "apartament", "Cluj", 400, 21312};
    struct Oferta oferta2 = {2, "apartament2", "Borsa", 500, 2312};
    struct Oferta oferta2_m = {2, "apartament3", "Borsa", 500, 2312};
    adaugare_oferta(repo, oferta);
    adaugare_oferta(repo, oferta);
    adaugare_oferta(repo, oferta2);
    int dim = 0;
    dimensiune(repo, &dim);
    assert(dim == 2);
    stergere_oferta(repo, 3);
    dimensiune(repo, &dim);
    assert(dim == 2);
    stergere_oferta(repo, 1);
    dimensiune(repo, &dim);
    assert(dim == 1);
    struct Oferta* lista = (struct Oferta*)malloc(dim * sizeof(struct Oferta));
    get_all_oferte(repo, lista, &dim);
    modificare_oferta(repo, 1, oferta);
    assert(strcmp(get_tip(&lista[0]), "apartament2") == 0);
    modificare_oferta(repo, 2, oferta2_m);
    get_all_oferte(repo, lista, &dim);
    assert(strcmp(get_tip(&lista[0]), "apartament3") == 0);
    free(lista);
    distrugeLista(repo);
}

void teste_validare(){
    struct Oferta oferta = {1, "apartament", "Cluj", 400, 21312};
    struct Oferta oferta2 = {-2, "apartamen", "", 0, -2312};
    char erori[200];
    validare_oferta(oferta, erori);
    assert(strlen(erori) == 0);
    validare_oferta(oferta2, erori);
    assert(strcmp(erori, "\nID invalid!\nTip invalid!\nAdresa invalida!\nSuprafata invalida!\nPret invalida!") == 0);
}

void teste_service(){
    MyList *repo = creazaLista();
    MyList *undolist = creazaLista();
    adaugareOferte(repo, undolist, 1, "apartament", "Cluj-Napoca", 500, 1213);
    adaugareOferte(repo, undolist, 2, "teren", "Borsa", 600, 2323);
    int dim;
    adaugareOferte(repo, undolist, 1, "apartamen", "Cluj-Napoca", 500, 1213);
    adaugareOferte(repo, undolist, 3, "casa", "Cluj", 500, 1234);
    Dim(repo, &dim);
    assert(dim == 3);
    modificareOferta(repo, undolist, 1, "apartament", "Baia Mare", 501, 2332);
    modificareOferta(repo, undolist, 1, "", "Baia Mare", 501, 2332);

    struct Oferta* lista = (struct Oferta*)malloc(50 * sizeof(struct Oferta));
    getAllOferte(repo, lista, &dim);
    assert(strcmp(get_adresa(&lista[0]), "Baia Mare") == 0);
    assert(get_suprafata(lista[0]) == 501);
    assert(get_pret(lista[0]) == 2332);
    modificareOferta(repo, undolist, 4, "apartament", "Baia Mare", 501, 2332);
    getAllOferte(repo, lista, &dim);
    for (int i = 1; i < dim; i ++)
        if (strcmp(get_adresa(&lista[i]), "Baia Mare") == 0) assert(0);
    stergereOferta(repo, undolist, 4);
    stergereOferta(repo, undolist, 1);
    Dim(repo, &dim);
    assert(dim == 2);
    stergereOferta(repo, undolist, 2);
    Dim(repo, &dim);
    assert(dim == 1);
    adaugareOferte(repo, undolist, 1, "casa", "Cluj-Napoca", 700, 100);
    adaugareOferte(repo, undolist, 2, "teren", "Borsa", 600, 600);
    adaugareOferte(repo, undolist, 4, "apartament", "Cluj-Napoca", 100, 100);
    adaugareOferte(repo, undolist, 5, "teren", "Borsa", 100, 700);
    odonareOferteDupaPretTip(repo, lista, sort_cresc_verif);
    Dim(repo, &dim);
    for (int i = 0; i < dim - 1; i ++)
        if (get_pret(lista[i]) > get_pret(lista[i + 1])) assert(0);
    odonareOferteDupaPretTip(repo, lista, sort_descresc_verif);
    Dim(repo, &dim);
    for (int i = 0; i < dim - 1; i ++)
        if (get_pret(lista[i]) < get_pret(lista[i + 1])) assert(0);
    ordonareBubble(repo, lista, sort_cresc_verif);
    Dim(repo, &dim);
    for (int i = 0; i < dim - 1; i ++)
        if (get_pret(lista[i]) > get_pret(lista[i + 1])) assert(0);
    ordonareBubble(repo, lista, sort_descresc_verif);
    Dim(repo, &dim);
    for (int i = 0; i < dim - 1; i ++)
        if (get_pret(lista[i]) < get_pret(lista[i + 1])) assert(0);
    int l;
    filtrareDupaUnCriteriu(repo, lista, &l, 2, 0, "teren", 0);
    assert(l == 2);
    filtrareDupaUnCriteriu(repo, lista, &l, 1, 100, "", 0);
    assert(l == 2);
    filtrareDupaUnCriteriu(repo, lista, &l, 3, 0, "", 600);
    assert(l == 1);
    filtrareNoua(repo, lista, &l, 400);
    assert(l == 3);
    free(lista);
    distrugeLista(repo);
    distrugeListaUndo(undolist);
}

void teste_lista(){
    MyList *lista = (MyList *) creazaVector();
    int a = 1234;
    int *v = &a;
    adauga((MyList *) lista, v);
    *v = 1213;
    adauga((MyList *) lista, v);
    adauga((MyList *) lista, v);
    assert(size((MyList *) lista) == 3);
    v = (int*)get((MyList *) lista, 1);
    assert(*v == 1213);
    sterge((MyList *) lista, 1);
    assert(size((MyList *) lista) == 2);
    MyList* copy = copyList((MyList *) lista);
    assert(size(copy) == 2);
    distruge((MyList *) lista);
    distruge(copy);
}

void run_all_tests(){
    teste_domeniu();
    teste_repository();
    teste_validare();
    teste_service();
    teste_lista();
}