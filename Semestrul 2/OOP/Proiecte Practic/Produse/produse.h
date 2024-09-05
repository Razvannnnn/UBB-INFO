#ifndef PRODUSE_H
#define PRODUSE_H

#include <QString>

class Produse
{
private:
    int id;
    QString nume;
    QString tip;
    double pret;
public:
    Produse(int id, QString nume, QString tip, double pret): id(id), nume(nume), tip(tip), pret(pret){}
    int getId(){
        return id;
    }
    QString getNume(){
        return nume;
    }
    QString getTip(){
        return tip;
    }
    double getPret(){
        return pret;
    }
    void setId(int id1){
        this->id = id1;
    }
    void setNume(QString nume1){
        this->nume = nume1;
    }
    void setTip(QString tip1){
        this->tip = tip1;
    }
    void setPret(double pret1){
        this->pret = pret1;
    }
};

#endif // PRODUSE_H
