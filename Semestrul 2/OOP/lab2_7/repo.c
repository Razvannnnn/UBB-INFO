#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cheltuieli.h"
#include "repo.h"
#include "lista.h"

void adaugare(cheltuiala c, Lista* l) {
    /*
     * Functie care adauga o cheltuiala in lista
     * preconditii: c de tip cheltuiala
     *              l de tip lista
     * postconditii: -
     */
    if(l->capacitate <= l->len + 1) {
        int capacitate = 2*l->capacitate;
        cheltuiala* array = (cheltuiala*)malloc(sizeof(cheltuiala) * capacitate);
        for(int i=0;i<l->len;i++) {
            array[i] = l->array[i];
        }
        free(l->array);
        l->array = array;
        l->capacitate = capacitate;
    }
    l->array[l->len] = c;
    l->len++;
}

void stergere(int nr, Lista* l) {
    /*
     * Functie care sterge o cheltuiala din lista
     * preconditii: nr - de tip int > 0
     *              l - de tip Lista
     * postconditii: -
     */
    int ok=0;
    for(int i=0; i<l->len; i++) {
        if(l->array[i].nr == nr) {
            destroyCheltuiala(&l->array[i]);
            ok=1;
        }
        if(ok==1 && i < l->len-1) {
            l->array[i]=l->array[i+1];
        }
    }
    if(ok==1) l->len--;
}

void modificare(cheltuiala c, Lista* l) {
    /*
     * Functie care modifica o cheltuiala din lista
     * preconditii: c - de tip cheltuiala
     *              l - de tip Lista
     * postcondtii: -
     */
    for(int i=0;i<l->len;i++)
    {
        if(l->array[i].nr == c.nr)
        {
            l->array[i].suma = c.suma;
            strcpy(l->array[i].tip, c.tip);
        }
    }
}

Lista filtrare_propr_nr(Lista* lista, int nr) {
    /*
     * Functie de filtrare a listei dupa nr apt
     * preconditii - lista - de tip Lista
     *             - nr - de tip int
     * postconditii - noua lista filtrata
     */
    Lista new_lista = createLista();

    for(int i=0;i<lista->len;i++) {
        if(lista->array[i].nr == nr) {
            cheltuiala cheltuiala = createCheltuiala();
            cheltuiala.nr = lista->array[i].nr;
            cheltuiala.suma = lista->array[i].suma;
            strcpy(cheltuiala.tip, lista->array[i].tip);
            adaugare(cheltuiala, &new_lista);
        }
    }
    return new_lista;
}

Lista filtrare_propr_suma(Lista* lista, int suma) {
    /*
     * Functie de filtrare a listei dupa suma cheltuielii
     * preconditii - lista - de tip Lista
     *             - suma - de tip int
     * postconditii - noua lista filtrata
     */
    Lista new_lista = createLista();

    for(int i=0;i<lista->len;i++) {
        if(lista->array[i].suma == suma) {
            cheltuiala cheltuiala = createCheltuiala();
            cheltuiala.nr = lista->array[i].nr;
            cheltuiala.suma = lista->array[i].suma;
            strcpy(cheltuiala.tip,  lista->array[i].tip);
            adaugare(cheltuiala, &new_lista);
        }
    }
    return new_lista;
}

Lista filtrare_propr_tip(Lista* lista, char* tip) {
    /*
     * Functie de filtrare a listei dupa tipul cheltuielii
     * preconditii - lista - de tip Lista
     *             - tip - de tip char
     * postconditii - noua lista filtrata
     */
    Lista new_lista = createLista();

    for(int i=0;i<lista->len;i++) {
        if(strcmp(lista->array[i].tip, tip) == 0) {
            cheltuiala cheltuiala = createCheltuiala();
            cheltuiala.nr = lista->array[i].nr;
            cheltuiala.suma = lista->array[i].suma;
            strcpy(cheltuiala.tip, lista->array[i].tip);
            adaugare(cheltuiala, &new_lista);
        }
    }
    return new_lista;
}

int compare(cheltuiala a, cheltuiala b, int propr, int ord) {
    /*
     * Functie utilizata la sortare
     */
    if(propr == 1) {
        if(ord == 1 ) return a.suma > b.suma;
        return a.suma < b.suma;
    }
    if(propr == 0) {
        if(ord == 1) return strcmp(a.tip, b.tip) > 0;
        return strcmp(a.tip, b.tip) < 0;
    }
    return -1;
}

Lista sortare(Lista lista, int propr, int ord) {
    /*
     * Sortarea listei dupa suma sau dupa tip
     * propr = 1 -> sortare dupa suma
     * propr = 0 -> sortare dupa tip
     * ord = 1 -> sortare crescatoare
     * ord = 0 -> sortare descrescatoare
     * preconditii - lista - de tip Lista
     *             - propr - de tip int
     *             - ord - de tip int
     * postconditii - lista sortata
     */
    int ok = 0;
    while(ok == 0) {
        ok = 1;
        for(int i=0;i<lista.len - 1;i++) {
            if(compare(lista.array[i], lista.array[i+1], propr, ord)) {
                cheltuiala auxiliar = lista.array[i];
                lista.array[i] = lista.array[i+1];
                lista.array[i+1] = auxiliar;
                ok = 0;
            }
        }
    }
    return lista;
}

int sort_cresc(cheltuiala cheltuialaA, cheltuiala cheltuialaB) {
    if(cheltuialaA.suma == cheltuialaB.suma){
        return strcmp(cheltuialaA.tip, cheltuialaB.tip) > 0;
    }
    return cheltuialaA.suma > cheltuialaB.suma;
}
int sort_descresc(cheltuiala cheltuialaA, cheltuiala cheltuialaB) {
    if(cheltuialaA.suma == cheltuialaB.suma){
        return strcmp(cheltuialaA.tip, cheltuialaB.tip) < 0;
    }
    return cheltuialaA.suma < cheltuialaB.suma;
}

Lista sortare2(Lista lista, int (*compare)()) {
    /*
     * Sortarea listei dupa suma sau dupa tip
     * propr = 1 -> sortare dupa suma
     * propr = 0 -> sortare dupa tip
     * ord = 1 -> sortare crescatoare
     * ord = 0 -> sortare descrescatoare
     * preconditii - lista - de tip Lista
     *             - propr - de tip int
     *             - ord - de tip int
     * postconditii - lista sortata
     */
    int ok = 0;
    while(ok == 0) {
        ok = 1;
        for(int i=0;i<lista.len - 1;i++) {
            if(compare(lista.array[i], lista.array[i+1])) {
                cheltuiala auxiliar = lista.array[i];
                lista.array[i] = lista.array[i+1];
                lista.array[i+1] = auxiliar;
                ok = 0;
            }
        }
    }
    return lista;
}

// TESTE

void test_adaugare() {
    Lista lista_ad = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip, "curent");

    assert(lista_ad.len == 0);
    adaugare(c1, &lista_ad);
    assert(lista_ad.len == 1);
    assert(lista_ad.array[0].nr == 250);
    assert(lista_ad.array[0].suma == 300);
    assert(strcmp(lista_ad.array[0].tip, "curent") == 0);

    destroyLista(&lista_ad);
}

void test_stergere() {
    Lista lista_st = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip, "curent");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 130;
    c2.suma = 100;
    strcpy(c2.tip, "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");

    assert(lista_st.len == 0);
    adaugare(c1, &lista_st);
    adaugare(c2, &lista_st);
    adaugare(c3, &lista_st);
    assert(lista_st.len == 3);
    stergere(250, &lista_st);
    assert(lista_st.len == 2);

    destroyLista(&lista_st);
}

void test_modificare() {
    Lista lista_modif = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip,  "curent");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 250;
    c2.suma = 100;
    strcpy(c2.tip, "apa");

    assert(lista_modif.len == 0);
    adaugare(c1, &lista_modif);
    assert(lista_modif.len == 1);
    modificare(c2, &lista_modif);
    assert(lista_modif.len == 1);
    assert(lista_modif.array[0].nr == 250 && lista_modif.array[0].suma == 100 && strcmp(lista_modif.array[0].tip, "apa") == 0);

    destroyCheltuiala(&c2);
    destroyLista(&lista_modif);
}

void test_filtrare_propr_nr() {
    Lista lista = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip,"curent");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 150;
    c2.suma = 100;
    strcpy(c2.tip,  "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");
    adaugare(c1, &lista);
    adaugare(c2, &lista);
    adaugare(c3, &lista);

    Lista new_lista = filtrare_propr_nr(&lista, 150);
    assert(new_lista.array[0].suma == 100);
    assert(strcmp(new_lista.array[0].tip, "apa") == 0);
    assert(new_lista.array[1].suma == 300);
    assert(strcmp(new_lista.array[1].tip, "caldura") == 0);

    destroyLista(&new_lista);
    destroyLista(&lista);
}

void test_filtrare_propr_suma() {
    Lista lista = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip, "curent");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 150;
    c2.suma = 100;
    strcpy(c2.tip,  "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");
    adaugare(c1, &lista);
    adaugare(c2, &lista);
    adaugare(c3, &lista);

    Lista new_lista = filtrare_propr_suma(&lista, 300);
    assert(new_lista.array[0].nr == 250);
    assert(strcmp(new_lista.array[0].tip, "curent") == 0);
    assert(new_lista.array[1].nr == 150);
    assert(strcmp(new_lista.array[1].tip, "caldura") == 0);

    destroyLista(&new_lista);
    destroyLista(&lista);
}

void test_filtrare_propr_tip() {
    Lista lista = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip, "apa");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 150;
    c2.suma = 100;
    strcpy(c2.tip, "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");
    adaugare(c1, &lista);
    adaugare(c2, &lista);
    adaugare(c3, &lista);

    Lista new_lista = filtrare_propr_tip(&lista, "apa");
    assert(new_lista.array[0].nr == 250);
    assert(new_lista.array[0].suma == 300);
    assert(new_lista.array[1].nr == 150);
    assert(new_lista.array[1].suma == 100);

    destroyLista(&new_lista);
    destroyLista(&lista);
}

void test_sortare() {
    Lista lista = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 300;
    strcpy(c1.tip, "apa");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 150;
    c2.suma = 100;
    strcpy(c2.tip,  "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");
    adaugare(c1, &lista);
    adaugare(c2, &lista);
    adaugare(c3, &lista);

    sortare(lista, 1, 1);
    assert(lista.array[0].suma == 100);
    assert(lista.array[1].suma == 300);
    assert(lista.array[2].suma == 300);

    sortare(lista, 1, 0);
    assert(lista.array[0].suma == 300);
    assert(lista.array[1].suma == 300);
    assert(lista.array[2].suma == 100);

    sortare(lista, 0, 1);
    assert(strcmp(lista.array[0].tip, "apa") == 0);
    assert(strcmp(lista.array[1].tip, "apa") == 0);
    assert(strcmp(lista.array[2].tip, "caldura") == 0);

    sortare(lista, 0, 0);
    assert(strcmp(lista.array[0].tip, "caldura") == 0);
    assert(strcmp(lista.array[1].tip, "apa") == 0);
    assert(strcmp(lista.array[2].tip, "apa") == 0);

    destroyLista(&lista);
}

void test_sortare2() {
    Lista lista_sort = createLista();
    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;

    c1.suma = 300;
    strcpy(c1.tip, "apa");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 150;
    c2.suma = 100;
    strcpy(c2.tip,  "apa");

    cheltuiala c3 = createCheltuiala();
    c3.nr = 150;
    c3.suma = 300;
    strcpy(c3.tip, "caldura");
    adaugare(c1, &lista_sort);
    adaugare(c2, &lista_sort);
    adaugare(c3, &lista_sort);

    sortare2(lista_sort, sort_cresc);
    assert(lista_sort.array[0].suma == 100);
    assert(lista_sort.array[1].suma == 300);
    assert(lista_sort.array[2].suma == 300);

    sortare2(lista_sort, sort_descresc);
    assert(lista_sort.array[0].suma == 300);
    assert(lista_sort.array[1].suma == 300);
    assert(lista_sort.array[2].suma == 100);

    sortare2(lista_sort, sort_cresc);
    assert(strcmp(lista_sort.array[0].tip, "apa") == 0);
    assert(strcmp(lista_sort.array[1].tip, "apa") == 0);
    assert(strcmp(lista_sort.array[2].tip, "caldura") == 0);

    sortare2(lista_sort, sort_descresc);
    assert(strcmp(lista_sort.array[0].tip, "caldura") == 0);
    assert(strcmp(lista_sort.array[1].tip, "apa") == 0);
    assert(strcmp(lista_sort.array[2].tip, "apa") == 0);

    destroyLista(&lista_sort);
}

void test_compare() {
    cheltuiala c1 = createCheltuiala();
    cheltuiala c2 = createCheltuiala();
    c1.suma = 100;
    c2.suma = 150;
    strcpy(c1.tip,  "apa");
    strcpy(c2.tip,  "caldura");

    assert(compare(c1, c2, 1, 1) == 0);
    assert(compare(c1, c2, 1, 0) == 1);
    assert(compare(c1, c2, 0, 1) == 0);
    assert(compare(c1, c2, 0, 0) == 1);
    assert(compare(c1, c2, 100, 1) == -1);

    destroyCheltuiala(&c1);
    destroyCheltuiala(&c2);
}