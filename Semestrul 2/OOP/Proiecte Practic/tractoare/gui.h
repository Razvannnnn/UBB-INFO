//
// Created by razva on 21.06.2024.
//

#ifndef TRACTOARE_GUI_H
#define TRACTOARE_GUI_H

#include "service.h"
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTableView>
#include <QString>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTableWidget>
#include <QComboBox>
#include "model.h"

using namespace std;

class GUI: public QWidget {
private:
    Service& srv;

    QVBoxLayout* layout = new QVBoxLayout;

    MyTable* model;
    QTableView* table = new QTableView;
    QComboBox* comboBox = new QComboBox;

    //QTableWidget* tabel;

    QLabel* lblid = new QLabel("ID:");
    QLabel* lbldenumire = new QLabel("Denumire:");
    QLabel* lbltip = new QLabel("Tip:");
    QLabel* lblnumarroti = new QLabel("Numar roti:");

    QLineEdit* editid = new QLineEdit;
    QLineEdit* editdenumire = new QLineEdit;
    QLineEdit* edittip = new QLineEdit;
    QLineEdit* editnumarroti = new QLineEdit;

    QPushButton* btnADD = new QPushButton("Adauga tractor");

    void initializeGUI();
    void connectSignals();
    void reloadGUI(vector<Tractor>& tractoare);
public:
    GUI(Service& srv) : srv{srv} {
        initializeGUI();
        connectSignals();
        reloadGUI(srv.getAll());
    }
};

#endif //TRACTOARE_GUI_H