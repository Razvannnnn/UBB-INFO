#ifndef ROCHII_GUI_H
#define ROCHII_GUI_H

#include <QApplication>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QString>
#include <QFormLayout>
#include <QCheckBox>
#include <QMessageBox>
#include <QColor>

#include "service.h"
#include "domain.h"
#include <vector>

using namespace std;

class GUI : public QWidget{
private:
    Service& srv;

    QLabel* lblCOD = new QLabel{"COD:"};
    QLabel* lblDenumire = new QLabel{"Denumire:"};
    QLabel* lblMarime = new QLabel{"Marime:"};
    QLabel* lblPret = new QLabel{"Pret"};
    QLabel* lblDisponibilitate = new QLabel{"Disponibilitate"};

    QLineEdit* editCOD;
    QLineEdit* editDenumire;
    QLineEdit* editMarime;
    QLineEdit* editPret;
    QCheckBox* editDisponibilitate;

    QPushButton* btnAddRochie;
    QPushButton* btnDelRochie;

    QListWidget* listaRochii;

    void initializeGUIApp();
    void connectSignals();
    void reloadGUI(vector<Rochie> rochii);
public:
    GUI(Service& srv) : srv{ srv } {
        initializeGUIApp();
        connectSignals();
        reloadGUI(srv.getAll());
    }

};

#endif //ROCHII_GUI_H
