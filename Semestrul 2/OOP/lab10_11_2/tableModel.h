#ifndef LAB6_TABLEMODEL_H
#define LAB6_TABLEMODEL_H

#pragma once
#include <QAbstractTableModel>
#include "produs.h"
#include <vector>
#include <qdebug.h>

using namespace std;

class TableModel : public QAbstractTableModel {
    std::vector<Produs> produse;
public:
    TableModel(const std::vector<Produs>& produse) : produse{produse } {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return produse.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }


    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        //qDebug() << "row:" << index.row() << " col:" << index.column() << " role" << role;
        if (role == Qt::DisplayRole) {
            Produs p = produse[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(p.getNume());
            }
            else if (index.column() == 1) {
                return QString::fromStdString(p.getTip());
            }
            else if (index.column() == 2) {
                return QString::number(p.getPret());
            }
            else if (index.column() == 3) {
                return QString::fromStdString(p.getProducator());
            }
        }

        return QVariant{};
    }

    void setProduse(const vector<Produs>& produse) {
        this->produse = produse;
        auto topLeft = createIndex(0, 0);
        auto bottomR = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomR);
    }
};

#endif //LAB6_TABLEMODEL_H
