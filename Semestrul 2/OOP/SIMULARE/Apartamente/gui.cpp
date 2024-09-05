//
// Created by razva on 21.05.2024.
//

#include "gui.h"

void GUI::initializeGUIComponents() {
    QHBoxLayout* main = new QHBoxLayout;
    this->setLayout(main);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);

    editPret = new QLineEdit;
    editStrada = new QLineEdit;
    editSuprafata = new QLineEdit;

    lyForm->addRow(lblStrada, editStrada);
    lyForm->addRow(lblSuprafata, editSuprafata);
    lyForm->addRow(lblPret, editPret);

    addApartament = new QPushButton("Adauga produs");
    delApartament = new QPushButton("Sterge produs");
    lyForm->addWidget(addApartament);
    lyForm->addWidget(delApartament);

    filtrSuprafST = new QLineEdit;
    filtrSuprafDR = new QLineEdit;
    filtrPretST = new QLineEdit;
    filtrPretDR = new QLineEdit;

    lyForm->addRow(lblSuprafST, filtrSuprafST);
    lyForm->addRow(lblSuprafDR, filtrSuprafDR);
    lyForm->addRow(lblPretST, filtrPretST);
    lyForm->addRow(lblPretDR, filtrPretDR);
    filtrareSupraf = new QPushButton("Filtreaza dupa suprafata");
    filtrarePret = new QPushButton("Filtreaza dupa pret");
    lyForm->addWidget(filtrareSupraf);
    lyForm->addWidget(filtrarePret);

    lyLeft->addWidget(form);

    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    this->listaApartamente = new QListWidget;
    lyRight->addWidget(listaApartamente);

    main->addWidget(left);
    main->addWidget(right);
}

void GUI::connectSignalsSlots() {
    QObject::connect(addApartament, &QPushButton::clicked, this, &GUI::GUIAddApart);
    QObject::connect(delApartament, &QPushButton::clicked, this, &GUI::GUIDelApart);

}

void GUI::reloadList(vector<Apartament> apartamente) {
    this->listaApartamente->clear();
    for(auto &apt : apartamente) {
        string a = apt.get_strada() + " - " + to_string(apt.get_suprafata()) + " - " + to_string(apt.get_pret());
        this->listaApartamente->addItem(QString::fromStdString(a));

        if(a)
    }
}

void GUI::GUIAddApart() {
        string strada;
        int pret, suprafata;
        strada = editStrada->text().toStdString();
        pret = editPret->text().toInt();
        suprafata = editSuprafata->text().toInt();

        editStrada->clear();
        editPret->clear();
        editSuprafata->clear();

        this->srv.adauga(suprafata, strada, pret);
        this->reloadList(this->srv.get_all());

        QMessageBox::information(this, "Info", QString::fromStdString("Apartament adaugat cu succes!"));
}

void GUI::GUIDelApart() {
    string strada;
    int pret, suprafata;
    strada = editStrada->text().toStdString();
    pret = editPret->text().toInt();
    suprafata = editSuprafata->text().toInt();

    editStrada->clear();
    editPret->clear();
    editSuprafata->clear();

    this->srv.sterge(suprafata, strada, pret);
    this->reloadList(this->srv.get_all());

    QMessageBox::information(this, "Info", QString::fromStdString("Apartament sters cu succes!"));
}
