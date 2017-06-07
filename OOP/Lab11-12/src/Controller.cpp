#include "Controller.h"
#include <algorithm>
#include "FileWatchlist.h"
#include "RepositoryExceptions.h"

using namespace std;

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& trailer, const int duration)
{
	Movie m{ title, genre, year, likes, trailer, duration };
	this->validator.validate(m);
	this->repo.addMovie(m);

	//record the action for undo
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, m));
}

void Controller::removeMovieFromRepository(const std::string& title)
{
	Movie m = this->repo.findByTitle(title);
	this->repo.removeMovie(m);

	//record the action for undo
	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, m));
}

void Controller::undo()
{
	if (undoActions.empty())
	{
		throw RepositoryException{ "There are no more actions to undo." };
	}

	try
	{
		undoActions.back()->executeUndo();
		undoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void Controller::addMovieToWatchlist(const Movie& movie)
{
	this->watchList.add(movie);
}

void Controller::removeMovieFromWatchlist(const std::string& title)
{
	this->watchList.del(title);
}

void Controller::addAllMoviesByGenreToWatchlist(const std::string& genre)
{
	vector<Movie> moviesByGenre = this->filterByGenre(genre);

	for (auto m : moviesByGenre)
		this->watchList.add(m);
}

std::vector<Movie> Controller::filterByGenre(const std::string& genre)
{
	vector<Movie> movies = this->repo.getMovies();
	int nMovies = count_if(movies.begin(), movies.end(),
		[genre](const Movie& m)
	{
		return m.getGenre() == genre;
	});

	vector<Movie> moviesByGenre(nMovies);
	copy_if(movies.begin(), movies.end(), moviesByGenre.begin(),
		[genre](const Movie& m)
	{
		return m.getGenre() == genre; 
	});

	return moviesByGenre;
}

void Controller::saveWatchlist(const std::string& filename)
{
	this->watchList.setFilename(filename);
	this->watchList.writeToFile();
}

void Controller::openWatchlist() const
{
	this->watchList.displayWatchlist();
}