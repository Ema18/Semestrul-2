//
// Created by Ema on 4/23/2017.
//

#pragma once
#include "Repository.h"
#include "Watchlist.h"

using namespace std;

class Controller
{
private:
	Repository repo;

public:
	/** Constructor */
	Controller() {};

	/** Constructor with parameters */
	Controller(const Repository& r) : repo(r) {};

	/** Getters for repository and the watchlist(also a repository) */
	Repository getRepo() const { return repo; }

	/** Adds a movie with the given data to the movie repository. */
	void addMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);

	/** Deletes a movie from the movie repository. */
	void deleteMovie(const std::string& title);

	/** Updates a movie from the movie repository. */
	void updateMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);

	/** Gets the position of a specific movie in the repository(by title) */
	int getPosition(const string& title) { return this->repo.getPosition(title); }

	/** Adds a movie to the watchlist */
	void addMovieToWatchlist(const Movie& movie);

	/** Returns an array with all the element from the repository */
	vector<Movie> getAllElems();

	void incLikes(const std::string title) { this->repo.incLikes(title); }

	void wtf(string filename);

	/** Destructor */
	~Controller() {};
};