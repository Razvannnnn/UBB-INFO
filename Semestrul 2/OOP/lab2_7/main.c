/*
    Creati o aplicatie modulara in C.
    Se cere interfata utilizator de tip consola.
    Datele introduse de utilizator trebuie validate.
    Folositi athitectura stratificata.
    Folositi dezvoltare dirijata de teste (Test Driven Development)
    Fiecare metoda din aplicatie trebuie specificat si testat.
    Implementati vector dinamic pentru lucru cu liste:
        - in prima saptamana puteti folosi reprezentarea cu un struct ( un vector static si lungime in el)
        - pana in saptamana 2 trebuie folosit alocare dinamica (sa acomodeze oricate elemente)
    Timp de lucru 2 saptamani.


    7. Administrator imobil

    Creati o aplicatie care permite gestiunea de cheltuieli lunare pentru apartamentele dintr-un bloc.
    Fiecare cheltuiala are: numarul apartamentului, suma, tipul (apa, canal, incalzire, gaz).
    Aplicatia permite:
    a) Adaugarea de cheltuieli pentru un apartament
    b) Modificarea unei cheltuieli existente (tipul, suma)
    c) Stergere cheltuiala
    d) Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul,apartament)
    e) Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)
 */


#include <string.h>
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include "ui.h"
#include "repo.h"
#include "lista.h"
#include "valid.h"
#include "service.h"

void test() {
    test_adaugare();
    test_modificare();
    test_stergere();
    test_srv_adaugare();
    test_srv_modificare();
    test_srv_stergere();
    test_filtrare_propr_nr();
    test_filtrare_propr_suma();
    test_filtrare_propr_tip();
    test_sortare();
    test_compare();
    test_sortare2();
}


int main() {
    // Definim lista
    Lista lista = createLista();

    // Facem testele si rulam aplicatia
    test();

    consola(&lista);
    //_CrtDumpMemoryLeaks();
    return 0;
}
