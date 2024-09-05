#ifndef PRACTICPRODUSE_MODEL_H
#define PRACTICPRODUSE_MODEL_H

#include <QAbstractTableModel>
#include "domain.h"
#include <vector>

using namespace std;

class MyTable: public QAbstractTableModel {
    vector<Produs> produse;
public:
    MyTable(vector<Produs> produse): produse{ produse } {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return produse.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Produs p = produse[index.row()];
            if(index.column() == 0) return QString::number(p.getId());
            if(index.column() == 1) return QString::fromStdString(p.getNume());
            if(index.column() == 2) return QString::fromStdString(p.getTip());
            if(index.column() == 3) return QString::number(p.getPret());
            if(index.column() == 4) return QString::number(p.getVocale());
        }
        return QVariant{};
    }

    QVariant setProduse(const vector<Produs> produse) {
        this->produse = produse;
        auto topLeft = createIndex(0,0);
        auto botRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, botRight);
    }
};

#endif //PRACTICPRODUSE_MODEL_H
