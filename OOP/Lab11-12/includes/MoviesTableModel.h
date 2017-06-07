#pragma once
#include <qabstractitemmodel.h>
#include "Watchlist.h"

class MoviesTableModel : public QAbstractTableModel
{
private:
	Watchlist& watch;

public:
	MoviesTableModel(Watchlist& w) : watch{ w } {}
	~MoviesTableModel();

	// three methods (abstract in the class QAbstractTableModel)
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;	// number of rows
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override; // number of colums
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override; // text content for a cell

	
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override; // add header data
	
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override; // when a cell is edited
	Qt::ItemFlags flags(const QModelIndex & index) const override;	// set certain properties of a cell
};