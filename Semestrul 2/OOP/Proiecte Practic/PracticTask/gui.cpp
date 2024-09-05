//
// Created by razva on 21.06.2024.
//

#include "gui.h"

void GUI::initializeGUI() {
    this->setLayout(main);

    model = new MyTable{service.getAll()};
    table->setModel(model);

    main->addWidget(table);
    main->addWidget(lblID);
    main->addWidget(editID);
    main->addWidget(lblDESCRIERE);
    main->addWidget(editDESCRIERE);
    main->addWidget(lblPROGRAMATOR);
    main->addWidget(editPROGRAMATOR1);
    main->addWidget(editPROGRAMATOR2);
    main->addWidget(editPROGRAMATOR3);
    main->addWidget(editPROGRAMATOR4);
    main->addWidget(lblSTARE);
    main->addWidget(editSTARE);
    main->addWidget(btnADD);
    main->addWidget(lblSEARCH);
    main->addWidget(editSEARCH);

}

void GUI::reloadGUI(vector<Task>& taskuri) {
    model->setTaskuri(taskuri);
}

void GUI::connectSignals() {
    QObject::connect(btnADD, &QPushButton::clicked, [this] {
        try {
            int id;
            string descriere, stare;
            vector<string> programatori;
            id = editID->text().toInt();
            descriere = editDESCRIERE->text().toStdString();
            stare = editSTARE->text().toStdString();
            if(!editPROGRAMATOR1->text().toStdString().empty()) programatori.push_back(editPROGRAMATOR1->text().toStdString());
            if(!editPROGRAMATOR2->text().toStdString().empty()) programatori.push_back(editPROGRAMATOR2->text().toStdString());
            if(!editPROGRAMATOR3->text().toStdString().empty()) programatori.push_back(editPROGRAMATOR3->text().toStdString());
            if(!editPROGRAMATOR4->text().toStdString().empty()) programatori.push_back(editPROGRAMATOR4->text().toStdString());

            editID->clear();
            editDESCRIERE->clear();
            editSTARE->clear();
            editPROGRAMATOR1->clear();
            editPROGRAMATOR2->clear();
            editPROGRAMATOR3->clear();
            editPROGRAMATOR4->clear();

            service.adauga(id, descriere, programatori, stare);
            reloadGUI(service.getAll());
            QMessageBox::information(this, "Info", QString::fromStdString("Task adaugat!"));
        } catch (SrvException& msg) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getMsg()));
        }
    });
    QObject::connect(editSEARCH, &QLineEdit::textChanged, [this] {
        string nume = editSEARCH->text().toStdString();
        reloadGUI(service.filtruNume(nume));
    });
}
