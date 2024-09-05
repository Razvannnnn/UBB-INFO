#include <iostream>
#include "repo.h"
#include "produs.h"
#include "ui.h"
#include "validare.h"

void rulareTeste() {
    testeREPO();
    testeService();
    Valid valid;
    teste_validare(valid);
    printf("Testele au fost rulate cu succes!\n");
}

int main() {
    rulareTeste();
    RepoProdus repo;
    serviceProdus service{repo};
    UI ui{service};
    ui.startUI();
    return 0;
}

/*
    1 Magazin

    Creați o aplicație care permite:
    · gestiunea unei liste de produse. Produs: nume, tip, preț, producător
    · adăugare, ștergere, modificare și afișare produse
    · căutare produs
    · filtrare produse după: preț, nume, producător
    · sortare produse după: nume, preț, nume + tip

 */