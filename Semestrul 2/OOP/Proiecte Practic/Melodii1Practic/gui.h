//
// Created by razva on 21.06.2024.
//

#ifndef MELODII1PRACTIC_GUI_H
#define MELODII1PRACTIC_GUI_H

#include "domain.h"
#include "repo.h"
#include "service.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QString>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QSlider>
#include "model.h"


class GUI: public QWidget {
private:
    Service& srv;

    QVBoxLayout* main = new QVBoxLayout;
    MyTable* model = new MyTable{srv.getAll()};
    QTableView* table = new QTableView;

    QLabel* lblID = new QLabel("ID:");
    QLabel* lblTITLU = new QLabel("Titlu:");
    QLabel* lblARTIST = new QLabel("Artist:");
    QLabel* lblRANK = new QLabel("Rank:");


    QLineEdit* editID = new QLineEdit;
    QLineEdit* editTITLU = new QLineEdit;
    QLineEdit* editARTIST = new QLineEdit;
    QLineEdit* editRANK = new QLineEdit;

    QPushButton* addButon = new QPushButton("Adauga");
    QPushButton* delButon = new QPushButton("Sterge");
    QPushButton* modifButon = new QPushButton("Modifica");

    QLabel* lblSlider = new QLabel;
    QSlider* slider = new QSlider;

    void initializeGUI();
    void connectSignals();
    void reloadGUI(vector<Melodie> melodii);
public:
    GUI(Service &srv) : srv{srv} {
        initializeGUI();
        connectSignals();
        reloadGUI(srv.getAll());
    }
};

#endif //MELODII1PRACTIC_GUI_H
