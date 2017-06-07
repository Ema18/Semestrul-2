#pragma once
#include <vector>
#include "Movie.h"

class Watchlist
{
protected:
	std::vector<Movie> movies;

public:
	/** Constructor */
	Watchlist(int capacity = 10);

	/** Adds a movie to the watchlist. */
	void add(const Movie& movie);

	/** Deletes a movie from the watchlist. */
	int del(string title);

	/** Gives suggestions of movies to the user
	* @param repo - the repository
	* @param needle - the genre after the user wants the movies to be filtered
	* @return an array of type DynamicVector with the filtered movies
	*/
	vector<Movie> getSuggestions(vector<Movie> repo, string needle);

	/** Getter for the Watchlist */
	const vector<Movie> getAll() { return this->movies; }

	/** Get the position of a movie in the watchlist, searching by its title */
	int getPosition(string name);
	int getSize() const { return this->movies.size(); }

	virtual ~Watchlist() {}
};