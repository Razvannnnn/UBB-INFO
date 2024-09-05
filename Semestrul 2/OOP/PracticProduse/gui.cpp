#include "gui.h"
#include "exception"

void GUI::initializeGUI() {
    lymain = new QHBoxLayout;
    this->setLayout(lymain);

    QWidget* left = new QWidget;
    lyleft = new QVBoxLayout;
    left->setLayout(lyleft);

    QWidget* form = new QWidget;
    lyform = new QFormLayout;
    form->setLayout(lyform);

    editid = new QLineEdit;
    editnume = new QLineEdit;
    editpret = new QLineEdit;
    edittip = new QLineEdit;

    lyform->addRow(lblid, editid);
    lyform->addRow(lblnume, editnume);
    lyform->addRow(lbltip, edittip);
    lyform->addRow(lblpret, editpret);
    addProdus = new QPushButton("Adauga produs");
    rmvProdus = new QPushButton("Sterge produs");
    lyform->addRow(addProdus);
    lyform->addRow(rmvProdus);

    lyleft->addWidget(form);

    QWidget* right = new QWidget;
    lyright = new QVBoxLayout;
    right->setLayout(lyright);

    model = new MyTable{srv.getAll()};
    table = new QTableView;
    table->setModel(model);
    lyright->addWidget(table);

    lymain->addWidget(left);
    lymain->addWidget(right);
}

void GUI::connectSignals() {
    QObject::connect(addProdus, &QPushButton::clicked, this, &GUI::adddProdus);
    QObject::connect(rmvProdus, &QPushButton::clicked, this, &GUI::rmvvProdus);
}

void GUI::reloadGUI() {
    model->setProduse(srv.getAll());
}

void GUI::adddProdus() {
    try {
        int id;
        string nume, tip;
        double pret;

        id = editid->text().toInt();
        nume = editnume->text().toStdString();
        tip = edittip->text().toStdString();
        pret = editpret->text().toDouble();

        editid->clear();
        editnume->clear();
        edittip->clear();
        editpret->clear();

        this->srv.add(id,nume,tip, pret);
        this->reloadGUI();

        QMessageBox::information(this, "Info", QString::fromStdString("Produs adaugat!"));
    } catch(SrvException& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
    }
}

void GUI::rmvvProdus() {
    try {
        int id;

        id = editid->text().toInt();

        editid->clear();

        this->srv.remove(id);
        this->reloadGUI();

        QMessageBox::information(this, "Info", QString::fromStdString("Produs sters!"));
    } catch(SrvException& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
    }
}
