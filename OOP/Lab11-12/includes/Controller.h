#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include "MovieValidator.h"
#include <memory>
#include "Undo.h"

class Controller
{
private:
	Repository& repo;
	FileWatchlist& watchList;
	MovieValidator validator;
	// a vector of unique_ptr of undo actions;
	// pointers are required, as we need polymorphism;
	// each add/remove action (on the repository) will be recorded in this vector
	std::vector<std::unique_ptr<UndoAction>> undoActions;

public:
	Controller(Repository& r, FileWatchlist& w, MovieValidator v) : repo{ r }, watchList{ w }, validator{ v } {}

	Controller(const Controller& ctrl) = delete;	// controller cannot be copied now, because it contains unique_ptr
	void operator=(const Controller& ctrl) = delete;	//same for assignment

	Repository getRepo() const { return repo; }
	std::vector<Movie> getAllMovies() const { return this->repo.getMovies(); }
	Watchlist& getWatchlist() const { return this->watchList; }
	std::vector<Movie> getMoviesFromWatchlist() { return this->watchList.getAll(); }

	void addMovieToRepository(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& trailer, const int duration);

	void removeMovieFromRepository(const std::string& title);

	void undo();


	void addMovieToWatchlist(const Movie& movie);
	void removeMovieFromWatchlist(const std::string& title);

	void addAllMoviesByGenreToWatchlist(const std::string& genre);

	std::vector<Movie> filterByGenre(const std::string& genre);

	/*
	void startWatchlist();
	void nextMovieWatchlist();
	*/

	void saveWatchlist(const std::string& filename);

	void openWatchlist() const;

	void incLikes(const std::string title) { this->repo.incLikes(title); }
};