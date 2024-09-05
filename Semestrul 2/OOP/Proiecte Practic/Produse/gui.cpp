#include "gui.h"
#include <QMessageBox>

void GUI::initializareGUI(){
    this->setLayout(this->mL);
    qDebug() << service.getAll().size();
    tv->setModel(model);
    mL->addWidget(tv);
    qh1->addWidget(lId);
    qh1->addWidget(lineId);
    mL->addLayout(qh1);
    qh2->addWidget(lName);
    qh2->addWidget(lineName);
    mL->addLayout(qh2);
    qh3->addWidget(lTip);
    qh3->addWidget(lineTip);
    mL->addLayout(qh3);
    qh4->addWidget(lPret);
    qh4->addWidget(linePret);
    mL->addLayout(qh4);
    mL->addWidget(bAdauga);

    slider->setMinimum(0);
    slider->setMaximum(100);

    mL->addWidget(slider);


}

void GUI::initializareConn(){
    QPushButton::connect(bAdauga,&QPushButton::clicked,[this](){
        QString err = service.adaugare(lineId->text().toInt(),lineName->text(),lineTip->text(),linePret->text().toDouble());
        if(err != ""){
            QMessageBox* mb = new QMessageBox();
            mb->setText(err);
            mb->show();
            return;
        }
        model->setVector(service.getAll());
    });

    QSlider::connect(slider,&QSlider::valueChanged,[this](){
        vector<Produse> vecto = service.filtrare(slider->value());
        model->setVector(vecto);
    });
}

void GUI::initializareFerestre(){
    vector<QString> tipuri;
    vector<Produse> vecto = service.getAll();
    for(auto& x:vecto){
        int ok = 1;
        for(QString& str:tipuri)
            if(str == x.getTip()){
                ok = 0;
                break;
            }
        if(ok == 1)
            tipuri.push_back(x.getTip());
    }
    for(QString& str:tipuri){
        NewWindow* w = new NewWindow(service,str);
        service.repo.addObserver(w);
        w->show();
    }
}
