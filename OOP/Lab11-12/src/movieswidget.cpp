#include "movieswidget.hpp"

movieswidget::movieswidget(Watchlist &w, QAbstractItemModel* model, QWidget * parent)
	: QWidget(parent), watch{ w }, tableModel{ model } 
{
	ui.setupUi(this);

	// force the columns to resize, according to the size of the tabe view
	this->ui.moviesTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.moviesTableView->setModel(this->tableModel);
	
	this->ui.moviesTableView->setSortingEnabled(true);
}

movieswidget::~movieswidget() {
	
}
