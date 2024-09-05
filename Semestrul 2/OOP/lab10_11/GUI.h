#ifndef LAB6_GUI_H
#define LAB6_GUI_H

#include <vector>
#include <string>
#include <QtWidgets/QApplication>
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

using std::vector;
using std::string;
class GUI : public QWidget {
private:

    serviceProdus& srv;

    QLabel* lblDenumire = new QLabel{ "Denumire oferta:" };
    QLabel* lblDestinatie = new QLabel{ "Destinatie oferta:" };
    QLabel* lblTip = new QLabel{"Tipul ofertei:"};
    QLabel* lblPret = new QLabel{ "Pret oferta:" };

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

    QPushButton* btnAllInclusive;
    QPushButton* btnCityBreak;
    QPushButton* btnHiking;
    QPushButton* btnMultiCountry;
    QPushButton* btnAltele;

    QPushButton* btnUndo;

    // pentru tabel
    QTableWidget* tableProduse;
    // pentru lista
    QListWidget* listaProduse;

    QPushButton* btnCos;
//    QWidget* fereastraCos;
    QPushButton* adaugaCos;
    QLineEdit* denumireProdusCos;
    QLineEdit* destinatieOfertaCos;
    QPushButton* adaugaRandomCos;
    QLineEdit* numarRandom;
    QPushButton* golesteCos;
    QListWidget* listaCos;
    QLineEdit* editExport;
    QPushButton* exportCos;
    QLabel* lblRandom = new QLabel{"Numar produse random:"};
    QLabel* lblExport = new QLabel{"Nume fisier:"};

    void initializeGUIComponents();

    void connectSignalsSlots();
    void reloadProdusList(vector<Produs> produse);

    void reloadProdusCosList(vector<Produs> produse);
public:
    GUI(serviceProdus& SrvProd) : srv{ SrvProd } {
        initializeGUIComponents();
        connectSignalsSlots();
        reloadProdusList(srv.getAll());
    }
    void guiAddProdus();
    void guiModifyProdus();
    void guiDeleteProdus();
};


#endif //LAB6_GUI_H
