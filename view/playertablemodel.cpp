#include "playertablemodel.h"

PlayerTableModel::PlayerTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void PlayerTableModel::setPlayerRank(shared_ptr<vector<shared_ptr<player_avg> > > pointer)
{
    beginResetModel();
    playerRank = pointer;
    endResetModel();
}

int PlayerTableModel::rowCount(const QModelIndex &parent) const
{
    return 10;//playerRank->size();
}

int PlayerTableModel::columnCount(const QModelIndex &parent) const
{
    return 20;
}

QVariant PlayerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::TextAlignmentRole)
        return int(Qt::AlignRight | Qt::AlignVCenter);
    else if (role == Qt::DisplayRole)
        return "test";

    return QVariant();
}

QVariant PlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    else if (orientation == Qt::Horizontal)
        return "test";
    else
        return section + 1;
}
