#ifndef MODEL_H
#define MODEL_H
#include "produse.h"

#include <QAbstractTableModel>
#include <vector>
#include <QString>
#include <cstring>
using namespace std;

class Model: public QAbstractTableModel{
private:
    vector<Produse> vec;
public:
    Model(const vector<Produse>& vec1): vec{vec1}{}
    int rowCount(const QModelIndex& parent) const override{
        return vec.size();
    }
    int columnCount(const QModelIndex& parent) const override{
        return 5;
    }
    QVariant data(const QModelIndex& index, int role) const override{
        if(!index.isValid() || index.row() >= vec.size())
            return QVariant();
        if(role == Qt::DisplayRole){
            Produse p = vec.at(index.row());
            if(index.column() == 0){
                return QString::fromStdString(to_string(p.getId()));
            }
            if(index.column() == 1){
                return p.getNume();
            }
            if(index.column() == 2){
                return p.getTip();
            }
            if(index.column() == 3){
                return QString::fromStdString(to_string(p.getPret()));
            }
            if(index.column() == 4){
                int y = 0;
                for(char x:p.getNume().toStdString())
                    if(strchr("aeiouAEIOU",x))
                        y++;
                return QString::fromStdString(to_string(y));
            }
        }
        return QVariant();
    }
    void setVector(const vector<Produse>& vec1){
        this->vec = vec1;
        auto topLeft =  createIndex(0,0);
        int x = vec.size();
        auto bottomR = createIndex(x,5);
        emit dataChanged(topLeft,bottomR);
        emit layoutChanged();
    }
};

#endif // MODEL_H
