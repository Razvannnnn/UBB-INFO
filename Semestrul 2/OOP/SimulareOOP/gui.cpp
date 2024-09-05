#include "gui.h"

void GUI::initializeGUI() {
    QWidget* main = new QWidget;
    QHBoxLayout* lyMain = new QHBoxLayout;
    lyMain->addWidget(main);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    lyLeft->addWidget(left);

    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    lyRight->addWidget(right);


    tabelProduse = new QTableWidget(1,2,this);
    lyRight->addWidget(tabelProduse);

    lyMain->addWidget(left);
    lyMain->addWidget(right);
}

void GUI::connectComponents() {

}

void GUI::reloadGUI(vector<Produs> &produse) {

    int i=0;
    for(auto & p : produse) {
        i++;
        tabelProduse->setRowCount(i);
        string denumire = p.getDenumire();
        int pret = p.getPret();
        QTableWidgetItem* item = new QTableWidgetItem{QString::number(p.getPret())};
        QTableWidgetItem* item2 = new QTableWidgetItem();
        this->tabelProduse->setItem(i, 2, item);
        this->tabelProduse->setItem(i, 2, item2);
    }
}
