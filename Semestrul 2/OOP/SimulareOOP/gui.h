#ifndef SIMULAREOOP_GUI_H
#define SIMULAREOOP_GUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "domain.h"
#include "vector"
#include "service.h"

class GUI : public QWidget {
private:
    Service& srv;

    QLabel* lblCod;
    QLabel* lblDenumire;
    QLabel* lblNumar;
    QLabel* lblPret;

    QLineEdit* editCod;
    QLineEdit* editDenumire;
    QLineEdit* editNumar;
    QLineEdit* editPret;

    QTableWidget* tabelProduse;

public:
    GUI(Service srv) : srv{srv} {
        initializeGUI();
        connectComponents();
        reloadGUI(srv.getAll());
    }

    void initializeGUI();
    void connectComponents();
    void reloadGUI(vector<Produs> &produse);
};

#endif //SIMULAREOOP_GUI_H
