#include "gui.h"

void GUI::initializeGUI() {
    QHBoxLayout* main = new QHBoxLayout;
    this->setLayout(main);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);

    lyForm->addRow(lblNr, editNr);
    lyForm->addRow(lblNume, editNume);
    lyForm->addRow(lblScoala, editScoala);

    addElev = new QPushButton("Adauga elev");
    delElev = new QPushButton("Sterge elev");
    lyForm->addWidget(addElev);
    lyForm->addWidget(delElev);

    lyLeft->addWidget(form);

    listaElevi = new QListWidget;
    lyRight->addWidget(listaElevi);

    main->addWidget(left);
    main->addWidget(right);
}

void GUI::connectComponents() {

}

void GUI::reloadGUI(vector<Elev> elevi) {

}
