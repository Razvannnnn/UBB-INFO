#ifndef PRACTICPRODUSE_GUI_H
#define PRACTICPRODUSE_GUI_H

#include "service.h"
#include <QString>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QTableWidget>
#include <QLayout>
#include <QFormLayout>
#include <QMessageBox>
#include "model.h"

using namespace std;

class GUI: public QWidget{
private:
    Service& srv;

    MyTable* model;
    QTableView* table;

    QHBoxLayout* lymain;
    QVBoxLayout* lyleft;
    QVBoxLayout* lyright;
    QFormLayout* lyform;

    QLabel* lblid = new QLabel{"ID:"};
    QLabel* lblnume = new QLabel{"Nume:"};
    QLabel* lbltip = new QLabel{"Tip:"};
    QLabel* lblpret = new QLabel{"Pret:"};

    QLineEdit* editid;
    QLineEdit* editnume;
    QLineEdit* edittip;
    QLineEdit* editpret;

    QPushButton* addProdus;
    QPushButton* rmvProdus;

    void initializeGUI();
    void connectSignals();
    void reloadGUI();
public:
    GUI(Service& srv) : srv{ srv } {
        initializeGUI();
        connectSignals();
        reloadGUI();
    }

    void adddProdus();
    void rmvvProdus();
    void run() {
        this->show();
    }
};

#endif //PRACTICPRODUSE_GUI_H
