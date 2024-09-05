#include "gui.h"

void GUI::initializeGUI() {

    this->setLayout(layout);

    model = new MyTable(srv.getAll());
    table->setModel(model);

    /*
    tabel->clear();
    tabel->setRowCount(srv.getAll().size());
    tabel->setColumnCount(4);
    int nr = 0;
    for(auto &t : srv.getAll()) {
        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(t.getId())));
        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(t.getDenumire())));
        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(t.getTip())));
        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(t.getNumarRoti())));
        nr++;
    }
     */

    layout->addWidget(table);
    //layout->addWidget(tabel);
    layout->addWidget(lblid);
    layout->addWidget(editid);
    layout->addWidget(lbldenumire);
    layout->addWidget(editdenumire);
    layout->addWidget(lbltip);
    layout->addWidget(edittip);
    layout->addWidget(lblnumarroti);
    layout->addWidget(editnumarroti);
    layout->addWidget(btnADD);

    for(auto &tip: srv.getTipuri()) {
        comboBox->addItem(QString::fromStdString(tip));
    }

    layout->addWidget(comboBox);
}


void GUI::reloadGUI(vector<Tractor>& tractoare) {
    model->setTractoare(tractoare);
    comboBox->clear();
    for(auto &tip: srv.getTipuri()) {
        comboBox->addItem(QString::fromStdString(tip));
    }

    /*
    tabel->clear();
    tabel->setRowCount(srv.getAll().size());
    tabel->setColumnCount(4);
    int nr = 0;
    for(auto &t : srv.getAll()) {
        tabel->setItem(nr, 0, new QTableWidgetItem(QString::number(t.getId())));
        tabel->setItem(nr, 1, new QTableWidgetItem(QString::fromStdString(t.getDenumire())));
        tabel->setItem(nr, 2, new QTableWidgetItem(QString::fromStdString(t.getTip())));
        tabel->setItem(nr, 3, new QTableWidgetItem(QString::number(t.getNumarRoti())));
        nr++;
    }
     */
}

void GUI::connectSignals() {
    QObject::connect(btnADD, &QPushButton::clicked, [this] {
        try {
            int id, numarRoti;
            string denumire, tip;
            id = editid->text().toInt();
            denumire = editdenumire->text().toStdString();
            tip = edittip->text().toStdString();
            numarRoti = editnumarroti->text().toInt();
            editid->clear();
            editdenumire->clear();
            edittip->clear();
            editnumarroti->clear();

            srv.adaugare(id, denumire, tip, numarRoti);
            reloadGUI(srv.getAll());
            QMessageBox::information(this, "Info", QString::fromStdString("Tractor adaugat!"));
        } catch (SrvException& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
        }
    });
    QObject::connect(comboBox, &QComboBox::currentIndexChanged, [this] {
        QString selectedTip = comboBox->currentText();
        model->setSelectedTip(selectedTip);
    });
}
