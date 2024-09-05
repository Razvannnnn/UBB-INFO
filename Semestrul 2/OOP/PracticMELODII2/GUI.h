#ifndef PRACTICMELODII2_GUI_H
#define PRACTICMELODII2_GUI_H

#include "service.h"
#include "repo.h"

#include <QWidget>
#include <QApplication>
#include <QTableView>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QString>
#include <QMessageBox>
#include <Model.h>
#include <QAbstractTableModel>

class GUI: public QWidget {
private:
    Service& srv;

    QHBoxLayout* lyMain;
    QVBoxLayout* lyLeft;
    QVBoxLayout* lyRight;
    QFormLayout* lyForm;

    QLabel* labelArtist = new QLabel{"Artist:"};
    QLabel* labelTitlu = new QLabel{"Titlu:"};
    QLabel* labelGen = new QLabel{"Gen:"};
    QLabel* labelID = new QLabel{"ID:"};

    QLineEdit* editID;
    QLineEdit* editArtist;
    QLineEdit* editTitlu;
    QLineEdit* editGen;

    QPushButton* addMelodie;
    QPushButton* rmvMelodie;

    MyTabel* model;
    QTableView* tabel;

    void initializeGUI();
    void connectSignals();
    void reloadMelodii(vector<Melodie>& melodii);
public:
    GUI(Service& srv) : srv{ srv } {
        initializeGUI();
        connectSignals();
        reloadMelodii(srv.getAll());
    }

    void guiAddMelodie();
    void guiRmvMelodie();
};

#endif //PRACTICMELODII2_GUI_H
