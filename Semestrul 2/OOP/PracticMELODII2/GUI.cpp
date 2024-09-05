#include "GUI.h"
#include <exception>

void GUI::initializeGUI() {
    lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    QWidget* left = new QWidget;
    lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    lyForm = new QFormLayout;
    form->setLayout(lyForm);

    editID = new QLineEdit;
    editArtist = new QLineEdit;
    editGen = new QLineEdit;
    editTitlu = new QLineEdit;

    lyForm->addRow(labelTitlu, editTitlu);
    lyForm->addRow(labelArtist, editArtist);
    lyForm->addRow(labelGen, editGen);
    addMelodie = new QPushButton("Adauga melodie");
    lyForm->addWidget(addMelodie);

    lyForm->addRow(labelID, editID);
    rmvMelodie = new QPushButton("Sterge melodie");
    lyForm->addWidget(rmvMelodie);

    lyLeft->addWidget(form);

    QWidget* right = new QWidget;
    lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    model = new MyTabel{srv.getAll()};
    tabel = new QTableView;
    tabel->setModel(model);
    lyRight->addWidget(tabel);

    lyMain->addWidget(left);
    lyMain->addWidget(right);
}

void GUI::connectSignals() {
    QObject::connect(addMelodie, &QPushButton::clicked, this, &GUI::guiAddMelodie);
    QObject::connect(rmvMelodie, &QPushButton::clicked, this, &GUI::guiRmvMelodie);
}

void GUI::reloadMelodii(vector<Melodie>& melodii) {
    model->setMelodii(melodii);
}

void GUI::guiAddMelodie() {
    try {
        string titlu = editTitlu->text().toStdString();
        string artist = editArtist->text().toStdString();
        string gen = editGen->text().toStdString();

        editArtist->clear();
        editTitlu->clear();
        editGen->clear();

        this->srv.add(titlu,artist,gen);
        this->reloadMelodii(this->srv.getAll());

        QMessageBox::information(this, "Info", QString::fromStdString("Melodie adaugata!"));
    } catch(SrvException& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
    }
}

void GUI::guiRmvMelodie() {
    try {
        int id = editID->text().toInt();

        editID->clear();

        this->srv.remove(id);
        this->reloadMelodii(this->srv.getAll());

        QMessageBox::information(this, "Info", QString::fromStdString("Melodie stearsa!"));
    } catch(SrvException& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
    }
}
