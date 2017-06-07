#include "MoviesTableModel.h"
#include <qbrush.h>
#include <qcolor.h>

MoviesTableModel::~MoviesTableModel()
{
}

int MoviesTableModel::rowCount(const QModelIndex& parent) const
{
	return this->watch.getSize();
}

int MoviesTableModel::columnCount(const QModelIndex& parent) const
{
	return 6;
}

QVariant MoviesTableModel::data(const QModelIndex& index, int role) const
{
	Movie currentMovie = this->watch.getAll()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(currentMovie.getTitle());
		case 1:
			return QString::fromStdString(currentMovie.getGenre());
		case 2:
			return QString::number(currentMovie.getYear());
		case 3:
			return QString::number(currentMovie.getLikes());
		case 4:
			return QString::fromStdString(currentMovie.getTrailer());
		case 5:
			return QString::number(currentMovie.getDuration());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant MoviesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Genre" };
			case 2:
				return QString{ "Year" };
			case 3:
				return QString{ "Likes" };
			case 4:
				return QString{ "Trailer" };
			case 5:
				return QString{ "Duration" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool MoviesTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Movie currentMovie = this->watch.getAll()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags MoviesTableModel::flags(const QModelIndex& index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}