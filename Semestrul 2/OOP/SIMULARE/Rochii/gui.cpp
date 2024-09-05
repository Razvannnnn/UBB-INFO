//
// Created by razva on 21.05.2024.
//

#include "gui.h"

void GUI::initializeGUIApp() {
    QHBoxLayout* main = new QHBoxLayout;
    this->setLayout(main);

    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);

    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    editCOD = new QLineEdit;
    editDenumire = new QLineEdit;
    editMarime = new QLineEdit;
    editPret = new QLineEdit;
    editDisponibilitate = new QCheckBox;

    lyForm->addRow(lblCOD, editCOD);
    lyForm->addRow(lblDenumire, editDenumire);
    lyForm->addRow(lblMarime, editMarime);
    lyForm->addRow(lblPret, editPret);
    lyForm->addRow(lblDisponibilitate, editDisponibilitate);

    btnAddRochie = new QPushButton("Adauga rochie");
    btnDelRochie = new QPushButton("Sterge rochie");
    lyForm->addWidget(btnAddRochie);
    lyForm->addWidget(btnDelRochie);

    lyLeft->addWidget(form);

    listaRochii = new QListWidget;
    lyRight->addWidget(listaRochii);

    main->addWidget(left);
    main->addWidget(right);
}

void GUI::connectSignals() {
    QObject::connect(btnAddRochie, &QPushButton::clicked, this, [&](){
        try{
            int cod, pret;
            string denumire, marime;
            bool disponibilitate;

            cod = editCOD->text().toInt();
            pret = editPret->text().toInt();
            denumire = editDenumire->text().toStdString();
            marime = editMarime->text().toStdString();
            disponibilitate = editDisponibilitate->isChecked();

            this->srv.adauga(cod, denumire, marime, pret, disponibilitate);
            this->reloadGUI(srv.getAll());

            QMessageBox::information(this, "Info", QString::fromStdString("Rochia a fost adaugata!"));
        }
        catch (RepoException &msg) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getMsg()));
        }
    });

    QObject::connect(btnDelRochie, &QPushButton::clicked, this, [&](){
        try{
            int cod, pret;
            string denumire, marime;
            bool disponibilitate;

            cod = editCOD->text().toInt();
            pret = editPret->text().toInt();
            denumire = editDenumire->text().toStdString();
            marime = editMarime->text().toStdString();
            disponibilitate = editDisponibilitate->isChecked();

            this->srv.sterge(cod, denumire, marime, pret, disponibilitate);
            this->reloadGUI(srv.getAll());

            QMessageBox::information(this, "Info", QString::fromStdString("Rochia a fost adaugata!"));
        }
        catch (RepoException &msg) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getMsg()));
        }
    });

}

void GUI::reloadGUI(vector<Rochie> rochii) {
    this->listaRochii->clear();
    for(auto & r : rochii) {
        string o = to_string(r.getCod()) + " - " + r.getDenumire() + " - " + r.getMarime() + " - " + to_string(r.getPret()) + " - " +
                to_string(r.getDisponibilitate()) + "\n";
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(o));

        if(r.getDisponibilitate()) {
            item->setForeground(Qt::green);
        } else {
            item->setForeground(Qt::red);
        }

        this->listaRochii->addItem(item);
    }
}
