//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICCC_MODEL_H
#define PRACTICCC_MODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "domain.h"
#include "repo.h"
#include "service.h"

using namespace std;


class MyTabel: public QAbstractTableModel {
    vector<Melodie> melodii;
public:
    MyTabel(vector<Melodie>& melodii) : melodii{ melodii } {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 6;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Melodie mel = melodii[index.row()];
            if(index.column() == 0 ) {
                return QString::number(mel.getId());
            }
            if(index.column() == 1 ) {
                return QString::fromStdString(mel.getTitlu());
            }
            if(index.column() == 2 ) {
                return QString::fromStdString(mel.getArtist());
            }
            if(index.column() == 3 ) {
                return QString::fromStdString(mel.getGen());
            }
        }
        return QVariant{};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
            if(section == 0) return QString("ID");
            if(section == 1) return QString("Titlu");
            if(section == 2) return QString("Artist");
            if(section == 3) return QString("Gen");
            if(section == 4) return QString("FR Autor");
            if(section == 5) return QString("FR Gen");
        }
        return QVariant{};
    }

    void setMelodii(const vector<Melodie>& melodii) {
        this->melodii = melodii;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
    }
};


#endif //PRACTICCC_MODEL_H
