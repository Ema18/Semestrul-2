#ifndef UI_H
#define UI_H

#include <QtWidgets/QWidget>
#include "ui_ui.h"
#include "Controller.h"
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include "movieswidget.hpp"
#include "MoviesTableModel.h"
#include <qsortfilterproxymodel.h>

class UI : public QWidget
{
	Q_OBJECT

public:
	UI(Controller& c, QWidget *parent = 0);
	~UI();

private:
	Controller& ctrl;
	std::vector<Movie> currentMoviesInRepoList;
	std::vector<Movie> currentMoviesInWatchList;

	QListWidget* repoList;
	QLineEdit* titleEdit;
	QLineEdit* genreEdit;
	QLineEdit* yearEdit;
	QLineEdit* likesEdit;
	QLineEdit* trailerEdit;
	QLineEdit* durationEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* filterButton;
	QPushButton* updateButton;

	QPushButton* moveOneMovieButton;
	QPushButton* moveAllMoviesButton;

	QPushButton* skipButton;
	QPushButton* watchTrailerButton;
	QPushButton* deleteWatchedButton;
	QPushButton* openFileButton;

	// Lab14
	QPushButton* undoButton;
	QPushButton* showWatchlistButton;

	QListWidget* watchList;

	Watchlist w = this->ctrl.getWatchlist();
	MoviesTableModel* tableModel = new MoviesTableModel{ this->w };
	QSortFilterProxyModel* sortModel = new QSortFilterProxyModel{};
	movieswidget moviesWidget{ this->w, this->sortModel };


	void initGUI();
	void populateRepoList();
	void populateWatchlist();
	int getRepoListSelectedIndex();

	int getWatchListSelectedIndex();

	void connectSignalsAndSlots();

	private slots:
	// Whem am item in the list is clicked, the boxes get filled with the item's information
	void listItemChanged();

	void addNewMovie();
	void deleteMovie();
	void updateRepoMovies();

	// filters the elements in the list, by the genre written in the genre edit box
	void filterRepoMovies();

	void moveMovieToWatchlist();
	void moveAllMovies();

	void watchTrailer();
	void deleteWatched();
	void openFile();

	void undo();
	void showWatchlist();
};

#endif // UI_H
