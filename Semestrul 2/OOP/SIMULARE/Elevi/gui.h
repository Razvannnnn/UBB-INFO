#ifndef ELEVI_GUI_H
#define ELEVI_GUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QListWidget>
#include "service.h"

class GUI : public QWidget {
private:
    Service& srv;

    QLabel* lblNr = new QLabel{"Nr Matricol:"};
    QLabel* lblScoala = new QLabel{"Scoala:"};
    QLabel* lblNume = new QLabel{"Nume:"};

    QLineEdit* editNr = new QLineEdit;
    QLineEdit* editNume = new QLineEdit;
    QLineEdit* editScoala = new QLineEdit;

    QPushButton* addElev;
    QPushButton* delElev;

    QListWidget* listaElevi;

    void initializeGUI();
    void connectComponents();
    void reloadGUI(vector<Elev> elevi);
public:
    GUI(Service& srv) : srv{ srv } {
        initializeGUI();
        connectComponents();
        reloadGUI(srv.getAll());
    }
};

#endif //ELEVI_GUI_H
