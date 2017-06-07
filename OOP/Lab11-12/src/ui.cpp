#include "ui.h"
#include <vector>
#include "Movie.h"
#include "Utils.h"
#include <qmessagebox.h>
#include "RepositoryExceptions.h"
#include "qdebug.h"

UI::UI(Controller& c, QWidget *parent) : ctrl{ c }, QWidget(parent)
{
	this->initGUI();
	this->currentMoviesInRepoList = this->ctrl.getAllMovies();
	this->currentMoviesInWatchList = this->ctrl.getMoviesFromWatchlist();
	this->populateRepoList();

	this->sortModel->setSourceModel(this->tableModel);
	this->moviesWidget.setWindowTitle("Watchlist");
}

UI::~UI()
{

}

void UI::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Prepare left side components - vertical layout with:
	// - list
	// - form layout with the movie data
	// - grid layout with buttons: add, delete, update, filter
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	// movie data
	QWidget* movieDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ movieDataWidget };
	this->titleEdit = new QLineEdit{};
	this->genreEdit = new QLineEdit{};
	this->yearEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->trailerEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	formLayout->addRow("&Title:", titleEdit);
	formLayout->addRow("&Genre:", genreEdit);
	formLayout->addRow("&Year:", yearEdit);
	formLayout->addRow("&Likes:", likesEdit);
	formLayout->addRow("&Trailer:", trailerEdit);
	formLayout->addRow("&Duration:", durationEdit);

	//buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->filterButton = new QPushButton("Filter");
	this->updateButton = new QPushButton("Update");
	this->undoButton = new QPushButton("Undo");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(filterButton, 0, 2);
	gridLayout->addWidget(updateButton, 0, 3);
	gridLayout->addWidget(undoButton, 0, 4);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All movies" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(movieDataWidget);
	leftSide->addWidget(buttonsWidget);

	// middle component: just three buttons - to add the movies from the repository to the watchlist
	//										- one to show the watchlist which inherits QAbstractTableModel (lab14)
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneMovieButton = new QPushButton{ ">> Move one movie" };
	this->moveAllMoviesButton = new QPushButton{ ">> Move all movies" };
	this->showWatchlistButton = new QPushButton{ "&Show Watchlist" };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneMovieButton);
	vLayoutUpperPart->addWidget(this->moveAllMoviesButton);
	vLayoutUpperPart->addWidget(this->showWatchlistButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right component: the watchlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	// watchlist
	watchList = new QListWidget{};

	// three buttons for the watchlist
	QWidget* watchlistButtonsWidget = new QWidget{};
	QHBoxLayout* watchlistButtonsLayout = new QHBoxLayout{ watchlistButtonsWidget };
	this->watchTrailerButton = new QPushButton{ "&Watch trailer" };
	this->deleteWatchedButton = new QPushButton{ "&Delete watched movie" };
	this->openFileButton = new QPushButton{ "&Open file" };
	watchlistButtonsLayout->addWidget(this->watchTrailerButton);
	watchlistButtonsLayout->addWidget(this->deleteWatchedButton);
	watchlistButtonsLayout->addWidget(this->openFileButton);

	// add everything to the right layout
	rightSide->addWidget(new QLabel{ "Watchlist" });
	rightSide->addWidget(watchList);
	rightSide->addWidget(watchlistButtonsWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	//connect the signals and slots
	this->connectSignalsAndSlots();
}

void UI::connectSignalsAndSlots()
{
	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	// add button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewMovie()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteMovie()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterRepoMovies()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateRepoMovies()));

	QObject::connect(this->moveOneMovieButton, SIGNAL(clicked()), this, SLOT(moveMovieToWatchlist()));
	QObject::connect(this->moveAllMoviesButton, SIGNAL(clicked()), this, SLOT(moveAllMovies()));

	QObject::connect(this->watchTrailerButton, SIGNAL(clicked()), this, SLOT(watchTrailer()));
	QObject::connect(this->deleteWatchedButton, SIGNAL(clicked()), this, SLOT(deleteWatched()));
	QObject::connect(this->openFileButton, SIGNAL(clicked()), this, SLOT(openFile()));

	QObject::connect(this->undoButton, SIGNAL(clicked()), this, SLOT(undo()));

	//QObject::connect(this->showWatchlistButton, SIGNAL(clicked()), this, SLOT(showWatchlist()));
	connect(this->showWatchlistButton, &QPushButton::clicked, this, &UI::showWatchlist);
}

void UI::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto m : this->currentMoviesInRepoList)
	{
		QString itemInList = QString::fromStdString(m.getTitle() + " - " + m.getGenre());
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->repoList->addItem(item3);
	}

	// set the selection on the first item in the list
	if (this->currentMoviesInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void UI::populateWatchlist()
{
	// clear the list, if there are elements in it
	if (this->watchList->count() > 0)
		this->watchList->clear();

	for (auto m : this->ctrl.getMoviesFromWatchlist())
	{
		QString itemInList = QString::fromStdString(m.getTitle() + " - " + m.getGenre());
		this->watchList->addItem(itemInList);
	}
}

int UI::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->titleEdit->clear();
		this->genreEdit->clear();
		this->yearEdit->clear();
		this->likesEdit->clear();
		this->trailerEdit->clear();
		this->durationEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

int UI::getWatchListSelectedIndex()
{
	if (this->watchList->count() == 0)
		return -1;

	// get the movie at the selected index
	QModelIndexList index = this->watchList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}

void UI::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Movie> movies = this->currentMoviesInRepoList;

	// get the movie at the selected index
	if (idx >= movies.size())
		return;
	Movie m = movies[idx];

	this->titleEdit->setText(QString::fromStdString(m.getTitle()));
	this->genreEdit->setText(QString::fromStdString(m.getGenre()));
	this->yearEdit->setText(QString::number(m.getYear()));
	this->likesEdit->setText(QString::number(m.getLikes()));
	this->trailerEdit->setText(QString::fromStdString(m.getTrailer()));
	this->durationEdit->setText(QString::number(m.getDuration()));
}

void UI::addNewMovie()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string genre = this->genreEdit->text().toStdString();
	int year = this->yearEdit->text().toInt();
	int likes = this->likesEdit->text().toInt();
	std::string trailer = this->trailerEdit->text().toStdString();
	int duration = this->durationEdit->text().toInt();

	try
	{
		this->ctrl.addMovieToRepository(title, genre, year, likes, trailer, duration);
		// refresh the list
		this->currentMoviesInRepoList = this->ctrl.getAllMovies();
		this->populateRepoList();
	}
	catch (MovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorAsString()));
	}
	catch (DuplicateMovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void UI::deleteMovie()
{
	std::string title = this->titleEdit->text().toStdString();
	
	try
	{
		this->ctrl.removeMovieFromRepository(title);
		// refresh the list
		this->currentMoviesInRepoList = this->ctrl.getAllMovies();
		this->populateRepoList();
	}
	catch (InexistentMovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void UI::updateRepoMovies()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string genre = this->genreEdit->text().toStdString();
	int year = this->yearEdit->text().toInt();
	int likes = this->likesEdit->text().toInt();
	std::string trailer = this->trailerEdit->text().toStdString();
	int duration = this->durationEdit->text().toInt();
	try
	{
		this->ctrl.removeMovieFromRepository(title);
		this->ctrl.addMovieToRepository(title, genre, year, likes, trailer, duration);
		// refresh the list
		this->currentMoviesInRepoList = this->ctrl.getAllMovies();
		this->populateRepoList();
	}
	catch (InexistentMovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
	catch (MovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorAsString()));
	}
	catch (DuplicateMovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void UI::filterRepoMovies()
{
	std::string genre = this->genreEdit->text().toStdString();
	if (genre == "")
	{
		this->currentMoviesInRepoList = this->ctrl.getAllMovies();
		this->populateRepoList();
		return;
	}

	this->currentMoviesInRepoList = this->ctrl.filterByGenre(genre);
	this->populateRepoList();
}

void UI::moveMovieToWatchlist()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentMoviesInRepoList.size())
		return;

	const Movie& m = this->currentMoviesInRepoList[idx];
	this->ctrl.addMovieToWatchlist(m);
	// refresh the list
	this->currentMoviesInWatchList = this->ctrl.getMoviesFromWatchlist();
	this->populateWatchlist();
}

void UI::moveAllMovies()
{
	for (auto m : this->currentMoviesInRepoList)
	{
		this->ctrl.addMovieToWatchlist(m);
	}
	// refresh the list
	this->currentMoviesInWatchList = this->ctrl.getMoviesFromWatchlist();
	this->populateWatchlist();
}

void UI::watchTrailer()
{
	int idx = this->getWatchListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Movie> movies = this->currentMoviesInWatchList;

	// get the movie at the selected index
	if (idx >= movies.size())
		return;
	Movie m = movies[idx];
	m.start();
}

void UI::deleteWatched()
{
	int idx = this->getWatchListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Movie> movies = this->currentMoviesInWatchList;

	// get the movie at the selected index
	if (idx >= movies.size())
		return;
	Movie m = movies[idx];
	
	QMessageBox::StandardButton liked;
	liked = QMessageBox::question(this, "Test", "Liked the movie?",
		QMessageBox::Yes | QMessageBox::No);
	if (liked == QMessageBox::Yes)
	{
		qDebug() << "Yes was clicked";
		this->ctrl.incLikes(m.getTitle());
	}
	else
	{
		qDebug() << "Yes was not clicked";
	}

	this->ctrl.removeMovieFromWatchlist(m.getTitle());
	// refresh the repository
	this->currentMoviesInWatchList = this->ctrl.getMoviesFromWatchlist();
	this->populateWatchlist();
	// refresh the watchlist
	this->currentMoviesInRepoList = this->ctrl.getAllMovies();
	this->populateRepoList();
}

void UI::openFile()
{
	this->ctrl.saveWatchlist("Movies.csv");
	this->ctrl.openWatchlist();
}

void UI::undo()
{
	try
	{
		this->ctrl.undo();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
	// refresh the list
	this->currentMoviesInRepoList = this->ctrl.getAllMovies();
	this->populateRepoList();
}

void UI::showWatchlist()
{
	this->w = this->ctrl.getWatchlist();
	this->tableModel = new MoviesTableModel{ this->w };
	this->sortModel->setSourceModel(tableModel);
	this->moviesWidget.show();
}