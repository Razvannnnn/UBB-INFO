#ifndef PRACTICTRACTOARE_MODEL_H
#define PRACTICTRACTOARE_MODEL_H

#include <QAbstractTableModel>
#include "service.h"
#include "domain.h"
#include "repo.h"
#include <vector>

using namespace std;

class MyTable: public QAbstractTableModel {
    vector<Tractor> tractoare;
public:
    MyTable(vector<Tractor>& tractoare) : tractoare{ tractoare } {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return tractoare.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index = QModelIndex(), int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Tractor tr = tractoare[index.row()];
            if(index.column() == 0) return QString::number(tr.getId());
            if(index.column() == 1) return QString::fromStdString(tr.getDenumire());
            if(index.column() == 2) return QString::fromStdString(tr.getTip());
            if(index.column() == 3) return QString::number(tr.getNumarRoti());
        }
        return QVariant{};
    }

    void setTractoare(const vector<Tractor>& tract) {
        this->tractoare = tract;
        auto topLeft = createIndex(0,0);
        auto botRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, botRight);
    }
};

#endif //PRACTICTRACTOARE_MODEL_H
