//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICTASK_MODEL_H
#define PRACTICTASK_MODEL_H

#include <QAbstractTableModel>

class MyTable: public QAbstractTableModel {
private:
    vector<Task> taskuri;
public:
    MyTable(vector<Task>& taskuri) : taskuri{ taskuri } {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return taskuri.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index = QModelIndex(), int role = Qt::DisplayRole) const override {
        if(role == Qt::DisplayRole) {
            Task task = taskuri[index.row()];
            if(index.column() == 0) return QString::number(task.getId());
            if(index.column() == 1) return QString::fromStdString(task.getDescriere());
            if(index.column() == 2) return QString::fromStdString(task.getStare());
            if(index.column() == 3) return QString::number(task.getProgramatori().size());
        }
        return QVariant{};
    }

    void setTaskuri(const vector<Task>& task) {
        this->taskuri = task;
        auto topLeft = createIndex(0,0);
        auto botRight = createIndex(rowCount(), columnCount());
        emit layoutChanged();
        emit dataChanged(topLeft, botRight);
    }

};

#endif //PRACTICTASK_MODEL_H
