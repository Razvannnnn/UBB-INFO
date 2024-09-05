#include <iostream>
#include "repo.h"
#include "produs.h"
#include "ui.h"
#include "GUI.h"
#include "validare.h"

#include <QApplication>
#include <QLabel>

void rulareTeste() {
    testeREPO();
    testeLABREPO();
    testeService();
    Valid valid;
    teste_validare(valid);
    printf("Testele au fost rulate cu succes!\n");
}

int main() {
    rulareTeste();
    //QApplication a(argc, argv);
    RepoProdus repo;

    //LabRepo repo;
    //repo.setProbabilitate(0.9);

    string filename = "C:\\Users\\razva\\Desktop\\OOP\\lab8_9\\produse.txt";
    //RepoProdusFile repo{filename};
    CosProduse cos;
    serviceProdus service{repo, cos};
    UI ui{service};
    ui.startUI();

    //GUI g{service};
    //g.show();
    //return a.exec();
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