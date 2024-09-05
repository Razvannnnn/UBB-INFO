#ifndef LAB6_TABELMODELGUI_H
#define LAB6_TABELMODELGUI_H

#include <vector>
#include <string>
#include <QtWidgets>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <qlistwidget.h>
#include <QStringList>
#include "service.h"
#include "CosCRUDGUI.h"
#include "CosReadOnlyGUI.h"
#include "tableModel.h"

using std::vector;
using std::string;
class GUIModel : public QWidget {
private:
    serviceProdus& srv;

    QHBoxLayout* lyMain;
    QVBoxLayout* lyLeft;
    QFormLayout* lyForm;
    QVBoxLayout* lyRight;
    QVBoxLayout* lyRRight;

    QLabel* lblNume = new QLabel{ "Nume produs:" };
    QLabel* lblTip = new QLabel{ "Tip produs:" };
    QLabel* lblPret = new QLabel{"Pret produs:"};
    QLabel* lblProducator = new QLabel{ "Producator produs:" };

    QLineEdit* editNume;
    QLineEdit* editTip;
    QLineEdit* editPret;
    QLineEdit* editProducator;

    QPushButton* btnAddProdus;
    QPushButton* btnModifyProdus;
    QPushButton* btnDeleteProdus;

    QGroupBox* groupBox = new QGroupBox(tr("Tip sortare"));

    QRadioButton* radioSrtNume = new QRadioButton(QString::fromStdString("Nume"));
    QRadioButton* radioSrtPret = new QRadioButton(QString::fromStdString("Pret"));
    QRadioButton* radioSrtNumeTip = new QRadioButton(QString::fromStdString("Nume+Tip"));
    QPushButton* btnSortProduse;

    QLabel* lblFilterCriteria = new QLabel{ "Numele dupa care se filtreaza:" };
    QLineEdit* editFilterNume;
    QPushButton* btnFilterProdus1;

    QLabel* lblFilterCriteria2 = new QLabel{ "Tipul dupa care se filtreaza:" };
    QLineEdit* editFilterTip;
    QPushButton* btnFilterProdus2;

    QLabel* lblFilterCriteria3 = new QLabel{ "Pretul dupa care se filtreaza:" };
    QLineEdit* editFilterPret;
    QPushButton* btnFilterProdus3;

    QLabel* lblFilterCriteria4 = new QLabel{ "Producatorul dupa care se filtreaza:" };
    QLineEdit* editFilterProducator;
    QPushButton* btnFilterProdus4;

    QPushButton* btnReloadData;
    QPushButton* btnUndo;

    QTableView* tblview = new QTableView;
    // pentru tabel
    TableModel* tableProduse;
    // pentru lista
    QListWidget* listaProduse;

    QPushButton* btnCos;
//    QWidget* fereastraCos;
    QPushButton* adaugaCos;
    QLineEdit* numeProdusCos;
    QLineEdit* tipProdusCos;
    QLineEdit* producatorProdusCos;
    QPushButton* adaugaRandomCos;
    QLineEdit* numarRandom;
    QPushButton* golesteCos;
    QListWidget* listaCos;
    QLineEdit* editExport;
    QPushButton* exportCos;
    QLabel* lblRandom = new QLabel{"Numar produse random:"};
    QLabel* lblExport = new QLabel{"Nume fisier:"};

    QPushButton* btnCosCRUDGUI;
    QPushButton* btnCosReadOnlyGUI;

    CosCRUDGUI* fereastraCos;
    CosReadOnlyGUI* fereastraRDONLY;


    void initializeGUIComponents();

    void connectSignalsSlots();
    void reloadProdusList(vector<Produs> produse);

    void reloadProdusCosList(vector<Produs> produse);
public:
    GUIModel(serviceProdus& SrvProd) : srv{ SrvProd } {
        initializeGUIComponents();
        tableProduse = new TableModel{srv.getAll()};
        tblview->setModel(tableProduse);
        connectSignalsSlots();
    }
    void adaugaButoane();
    void guiAddProdus();
    void guiModifyProdus();
    void guiDeleteProdus();
};

#endif //LAB6_TABELMODELGUI_H
