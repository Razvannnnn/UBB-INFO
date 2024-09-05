#include <iostream>
#include "repo.h"
#include "ui.h"
#include "validare.h"
#include "GUI.h"
#include "tabelModelGUI.h"

#include <QApplication>

void rulareTeste() {
    testeREPO();
    testeLABREPO();
    testeService();
    Valid valid;
    teste_validare(valid);
    printf("Testele au fost rulate cu succes!\n");
}

int main(int argc, char* argv[]) {
    rulareTeste();
    QApplication app(argc, argv);
    //RepoProdus repo;

    //LabRepo repo;
    //repo.setProbabilitate(0.9);

    string filename = "C:\\Users\\razva\\Desktop\\OOP\\lab10_11_2\\produse.txt";
    RepoProdusFile repo{filename};
    CosProduse cos{repo};
    serviceProdus service{repo};

    //UI ui{service};
    //ui.startUI();
    GUIModel gui{service};
    gui.show();

    return app.exec();
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