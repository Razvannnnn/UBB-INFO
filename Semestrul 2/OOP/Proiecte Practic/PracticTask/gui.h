//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICTASK_GUI_H
#define PRACTICTASK_GUI_H

#include "service.h"
#include "domain.h"
#include "repo.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLayout>
#include <QApplication>
#include <QTableView>
#include <QPushButton>
#include <QMessageBox>
#include "model.h"

class GUI: public QWidget {
private:
    Service& service;

    QVBoxLayout* main = new QVBoxLayout;
    MyTable* model = new MyTable{service.getAll()};
    QTableView* table = new QTableView;

    QLabel* lblID = new QLabel("ID:");
    QLabel* lblDESCRIERE = new QLabel("Descriere:");
    QLabel* lblPROGRAMATOR = new QLabel("Programatori");
    QLabel* lblSTARE = new QLabel("Stare:");

    QLabel* lblSEARCH = new QLabel("Cauta programator");
    QLineEdit* editSEARCH = new QLineEdit;

    QLineEdit* editID = new QLineEdit;
    QLineEdit* editDESCRIERE = new QLineEdit;
    QLineEdit* editPROGRAMATOR1 = new QLineEdit;
    QLineEdit* editPROGRAMATOR2 = new QLineEdit;
    QLineEdit* editPROGRAMATOR3 = new QLineEdit;
    QLineEdit* editPROGRAMATOR4 = new QLineEdit;
    QLineEdit* editSTARE = new QLineEdit;

    QPushButton* btnADD = new QPushButton("Adauga Task");

    void initializeGUI();
    void connectSignals();
    void reloadGUI(vector<Task>& taskuri);
public:
    GUI(Service& service) : service{service} {
        initializeGUI();
        connectSignals();
        reloadGUI(service.getAll());
    }

};

#endif //PRACTICTASK_GUI_H
