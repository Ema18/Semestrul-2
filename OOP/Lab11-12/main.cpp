#include "ui.h"
#include <QtWidgets/QApplication>
#include "CSVWatchlist.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "Movies.txt" };
	CSVWatchlist watchlist;
	Controller ctrl{ repo, watchlist, MovieValidator{} };
	UI w{ ctrl };
	w.show();

	//Movie m = Movie("PotC", "Adventure", 2017, 900, "www.youtube.com", 123);
	//watchlist.add(m);

	/*
	MoviesTableModel* tableModel = new MoviesTableModel{ watchlist };

	QSortFilterProxyModel* sortModel = new QSortFilterProxyModel{};
	sortModel->setSourceModel(tableModel);
	movieswidget moviesWidget{ watchlist, sortModel };
	moviesWidget.setWindowTitle("Main");
	moviesWidget.show();
	*/

	return a.exec();
}
