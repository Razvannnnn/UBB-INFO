#ifndef APARTAMENTE_GUI_H
#define APARTAMENTE_GUI_H

#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QString>
#include <QObject>
#include "service.h"

class GUI : public QWidget{
private:
    Service &srv;

    QLabel* lblSuprafata = new QLabel{"Suprafata:"};
    QLabel* lblStrada = new QLabel{"Strada:"};
    QLabel* lblPret = new QLabel{"Pret:"};

    QLineEdit* editSuprafata;
    QLineEdit* editStrada;
    QLineEdit* editPret;

    QLabel* lblSuprafST = new QLabel{"Suprafata minima:"};
    QLabel* lblSuprafDR = new QLabel{"Suprafata maxima:"};
    QLabel* lblPretST = new QLabel{"Pret minim:"};
    QLabel* lblPretDR = new QLabel{"Pret maxim:"};

    QLineEdit* filtrSuprafST;
    QLineEdit* filtrSuprafDR;
    QLineEdit* filtrPretST;
    QLineEdit* filtrPretDR;

    QPushButton* addApartament;
    QPushButton* delApartament;

    QPushButton* filtrareSupraf;
    QPushButton* filtrarePret;

    QListWidget* listaApartamente;


    void initializeGUIComponents();
    void connectSignalsSlots();
    void reloadList(vector<Apartament> apartamente);
public:
    GUI(Service &srv) : srv{ srv } {
        initializeGUIComponents();
        connectSignalsSlots();
        reloadList(srv.get_all());
    }
    void GUIAddApart();
    void GUIDelApart();
};

#endif //APARTAMENTE_GUI_H
