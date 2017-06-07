#pragma once
#include <QWidget>
#include "ui_movieswidget.h"
#include "Watchlist.h"

class movieswidget : public QWidget {
	Q_OBJECT

public:
	movieswidget(Watchlist &w, QAbstractItemModel* model, QWidget * parent = 0);
	~movieswidget();

private:
	Ui::movieswidget ui;
	Watchlist& watch;

	QAbstractItemModel* tableModel;
};
