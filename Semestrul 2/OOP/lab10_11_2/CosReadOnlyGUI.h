#ifndef LAB6_COSREADONLYGUI_H
#define LAB6_COSREADONLYGUI_H

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
#include <QPainter>
#include <time.h>

class CosReadOnlyGUI : public QWidget, public Observer {
private:
    CosProduse& cos;
public:
    CosReadOnlyGUI(CosProduse& cos): cos{ cos } {
        cos.addObserver(this);
    }

    void update() override {
        repaint();
    }

    void paintEvent(QPaintEvent* event) override {
        QPainter pnt{ this };
        srand(time(NULL));
        for(auto& p : cos.getAllCos()) {
            int x = rand() % 300;
            int y = rand() % 300;
            qDebug() << x <<" "<<y<<"\n";
            pnt.drawRect(x,y,20,p.getPret());
            pnt.drawImage(x,y,QImage("C:\\Users\\razva\\Desktop\\OOP\\lab10_11_2\\sky.jpg"));
        }
    }

    ~CosReadOnlyGUI() {
        cos.removeObserver(this);
    }
};

#endif //LAB6_COSREADONLYGUI_H
