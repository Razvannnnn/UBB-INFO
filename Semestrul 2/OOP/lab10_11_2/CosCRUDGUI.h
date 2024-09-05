#ifndef LAB6_COSCRUDGUI_H
#define LAB6_COSCRUDGUI_H

#include "observer.h"
#include "CosProduse.h"
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>

class CosCRUDGUI : public QWidget, public Observer {
private:
    CosProduse& cos;
    QListWidget* list;
    QPushButton* btn;
    QPushButton* btnRandom;
    QLineEdit* editbtnRandom;
    QLabel* lblbtnRandom;

    void loadList(std::vector<Produs>& produse) {
        list->clear();
        for(auto &p : produse) {
            auto item = new QListWidgetItem(
                    QString::fromStdString(p.getNume() + " " + p.getTip() + " " + std::to_string(p.getPret()) + " " + p.getProducator())
                    );
            list->addItem(item);
        }
    }
    void initiliazeGUI() {
        QVBoxLayout* ly = new QVBoxLayout;
        list = new QListWidget;
        ly->addWidget(list);
        btn = new QPushButton("Clear cos");
        ly->addWidget(btn);

        btnRandom = new QPushButton("Generare 4 produse:");
        ly->addWidget(btnRandom);
        setLayout(ly);
    }
    void connectSignals() {
        cos.addObserver(this);
        QObject::connect(btn, &QPushButton::clicked, [&]() {
            cos.stergeCos();
            loadList(cos.getAllCos());
        });
        QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
            cos.fill(4);
            loadList(cos.getAllCos());
        });
    }

public:
    CosCRUDGUI(CosProduse& cos): cos{ cos } {
        initiliazeGUI();
        connectSignals();
        loadList(cos.getAllCos());
    }

    void update() override {
        loadList(cos.getAllCos());
    }

    ~CosCRUDGUI() {
        cos.removeObserver(this);
    }
};

#endif //LAB6_COSCRUDGUI_H
