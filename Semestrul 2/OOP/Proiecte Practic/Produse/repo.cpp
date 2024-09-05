#include "repo.h"
#include <fstream>
#include <QStringList>

#include <QDebug>

void Repo::loadFromFile(){
    ifstream fin(this->fisier);
    string line;
    while(getline(fin,line)){
        QString Qline = QString::fromStdString(line);
        QStringList list = Qline.split(';');
        Produse p(list.at(0).toInt(),list.at(1),list.at(2),list.at(3).toDouble());
        this->lista.push_back(p);
    }
    fin.close();
}

void Repo::loadToFile(){
    ofstream fout(this->fisier);
    for(auto x:this->lista){
        string obj = to_string(x.getId())+";"+x.getNume().toStdString()+";"+x.getTip().toStdString()+";"+to_string(x.getPret());
        fout << obj << "\n";
    }
}
