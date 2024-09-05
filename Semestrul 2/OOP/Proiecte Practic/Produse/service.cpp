#include "service.h"
#include "algorithm"
#include <QDebug>

QString Service::validator(int id, QString nume, QString tip, double pret){
    QString erori = "";
    vector<Produse> v = this->repo.getAll();
    for(auto x:v){
        if(x.getId()==id){
            erori+="Id-ul nu este unic\n";
            break;
        }
    }
    if(pret<1.0)
        erori+="Pret prea mic\n";
    if(pret>100.0)
        erori+="Pret prea mare\n";
    if(nume == "")
        erori+="nume invalid\n";
    return erori;
}

QString Service::adaugare(int id, QString nume, QString tip, double pret){
    if(this->validator(id,nume,tip,pret) == ""){
        Produse p(id,nume,tip,pret);
        repo.adaugare(p);
        return "";
    }
    else
        return this->validator(id,nume,tip,pret);
}

vector<Produse> Service::filtrare(int x){
    vector<Produse> p1;
    vector<Produse> p2 = repo.getAll();
    copy_if(p2.begin(),p2.end(),back_inserter(p1),[x](Produse& p){
        return x>p.getPret();
    });
    return p1;
}
