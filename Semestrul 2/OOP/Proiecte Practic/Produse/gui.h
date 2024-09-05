#ifndef GUI_H
#define GUI_H

#include "service.h"
#include "produse.h"

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "Model.h"
#include <QSlider>
#include "Observer.h"

class NewWindow: public Observer, public QWidget{
private:
    Service& s;
    QHBoxLayout* layout = new QHBoxLayout;
    QString tip;
    QLabel* numar = new QLabel;
public:
    NewWindow(Service& s,QString tip1):s(s),tip(tip1){
        this->setLayout(layout);
        layout->addWidget(numar);
        this->setWindowTitle(tip);
        doUpdate();
    }
    void doUpdate() override{
        int nr = 0;
        vector<Produse> vecto = s.getAll();
        for(auto& x:vecto){
            if(tip == x.getTip())
                nr++;
        }
        qDebug()<<nr;
        numar->setText(QString::fromStdString(to_string(nr)));
    }
};

class GUI: public QWidget
{
private:
    Service& service;

    QVBoxLayout* mL = new QVBoxLayout;

    QTableView* tv = new QTableView;
    Model* model = new Model{service.getAll()};

    QSlider* slider = new QSlider;

    QLineEdit* lineId = new QLineEdit;
    QLineEdit* lineName = new QLineEdit;
    QLineEdit* lineTip = new QLineEdit;
    QLineEdit* linePret = new QLineEdit;
    QLabel* lId = new QLabel("Id: ");
    QLabel* lName = new QLabel("Nume: ");
    QLabel* lTip = new QLabel("Tip: ");
    QLabel* lPret = new QLabel("Pret: ");
    QHBoxLayout* qh1 = new QHBoxLayout;
    QHBoxLayout* qh2 = new QHBoxLayout;
    QHBoxLayout* qh3 = new QHBoxLayout;
    QHBoxLayout* qh4 = new QHBoxLayout;

    QPushButton* bAdauga = new QPushButton("Adauga produs");



public:
    GUI(Service &s):service(s){
        initializareGUI();
        initializareConn();
        initializareFerestre();
    }
    void initializareGUI();
    void initializareConn();
    void initializareFerestre();
};

#endif // GUI_H
