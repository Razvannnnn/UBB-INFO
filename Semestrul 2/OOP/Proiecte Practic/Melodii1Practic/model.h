//
// Created by razva on 21.06.2024.
//

#ifndef MELODII1PRACTIC_MODEL_H
#define MELODII1PRACTIC_MODEL_H

#include <vector>
#include "domain.h"
#include <QAbstractTableModel>

class MyTable : public QAbstractTableModel {
private:
    vector<Melodie> melodii;
public:
    MyTable(vector<Melodie> melodii) : melodii{melodii} {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Melodie mel = melodii[index.row()];
            if(index.column() == 0) return QString::number(mel.getID());
            if(index.column() == 1) return QString::fromStdString(mel.getTitlu());
            if(index.column() == 2) return QString::fromStdString(mel.getArtist());
            if(index.column() == 3) return QString::number(mel.getRank());
            if(index.column() == 4) {
                int k=0;
                for(auto m : this->melodii) {
                    if(mel.getRank() == m.getRank()) k++;
                }
                return QString::number(k);
            }
        }
        return QVariant{};
    }

    void setMelodii(vector<Melodie> melodii) {
        this->melodii = melodii;
        auto topLeft = createIndex(0,0);
        auto botRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, botRight);
    }
};

#endif //MELODII1PRACTIC_MODEL_H
