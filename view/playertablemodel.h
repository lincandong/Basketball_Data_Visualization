#ifndef PLAYER_TABLEMODEL_H
#define PLAYER_TABLEMODEL_H

#include <QAbstractTableModel>
#include <memory>
using namespace std;
#include "../common/dataType.h"

class PlayerTableModel : public QAbstractTableModel
{
public:
    PlayerTableModel(QObject *parent = 0);

    void setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> pointer);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    shared_ptr<vector<shared_ptr<player_avg>>> playerRank;
};

#endif // PLAYER_TABLEMODEL_H
