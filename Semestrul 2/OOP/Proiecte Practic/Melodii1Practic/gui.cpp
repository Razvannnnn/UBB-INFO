//
// Created by razva on 21.06.2024.
//

#include "gui.h"

void GUI::initializeGUI() {
    this->setLayout(main);
    table->setModel(model);

    main->addWidget(table);

    main->addWidget(lblID);
    main->addWidget(editID);
    main->addWidget(lblTITLU);
    main->addWidget(editTITLU);
    main->addWidget(lblARTIST);
    main->addWidget(editARTIST);
    main->addWidget(lblRANK);
    main->addWidget(editRANK);
    main->addWidget(lblSlider);
    slider->setMinimum(1);
    slider->setMaximum(10);
    main->addWidget(slider);
    main->addWidget(addButon);
    main->addWidget(delButon);
    main->addWidget(modifButon);

}

void GUI::connectSignals() {
    QObject::connect(addButon, &QPushButton::clicked, [this] {
        try {
            int id, rank;
            string titlu, artist;
            id = editID->text().toInt();
            rank = editRANK->text().toInt();
            titlu = editTITLU->text().toStdString();
            artist = editARTIST->text().toStdString();

            editID->clear();
            editARTIST->clear();
            editTITLU->clear();
            editRANK->clear();

            srv.add(id, titlu, artist, rank);
            reloadGUI(srv.getAll());
            QMessageBox::information(this, "Info", QString::fromStdString("Melodie adaugata!"));
        } catch(SrvException& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
        }
    });
    QObject::connect(delButon, &QPushButton::clicked, [this] {

    });
    QObject::connect(modifButon, &QPushButton::clicked, [this] {
        int rank, id;
        string titlu;

        titlu = editTITLU->text().toStdString();
        rank = lblSlider->text().toInt();
        id = editID->text().toInt();

        srv.modify(id, titlu, rank);
        reloadGUI(srv.getAll());

    });
    QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [this] {
       if(table->selectionModel()->selectedIndexes().isEmpty()) {
           editTITLU->setText("");
           slider->setSliderPosition(1);
           return;
       } else {
           auto row = table->selectionModel()->selectedIndexes().at(0).row();
           auto titlu = table->model()->data(table->model()->index(row, 1), Qt::DisplayRole).toString();
           auto rank = table->model()->data(table->model()->index(row, 3), Qt::DisplayRole).toInt();
           auto id = table->model()->data(table->model()->index(row, 0), Qt::DisplayRole).toInt();
           editTITLU->setText(titlu);
           slider->setSliderPosition(rank);
           lblSlider->setText(QString::number(rank));
           editID->setText(QString::number(id));
       }
    });
    QObject::connect(slider, &QSlider::sliderMoved, [this] {
        int value = slider->value();
        lblSlider->setText(QString::number(value));
    });
}


void GUI::reloadGUI(vector<Melodie> melodii) {
    model->setMelodii(melodii);

}
