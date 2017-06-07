//
// Created by Ema on 4/23/2017.
//

#pragma once
#include <vector>
#include "Movie.h"

using namespace std;

class Watchlist
{
protected:
	vector<Movie> movieList;

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
	const vector<Movie> getArray();

	/** Get the position of a movie in the watchlist, searching by its title */
	int getPosition(string name);

	virtual void writeToFile1(string filename) = 0;
	virtual void openInApp() = 0;
};

class WatchlistCSV : public Watchlist
{
public:
	WatchlistCSV(int capacity) : Watchlist(capacity) {}

	void writeToFile1(string filename) override;
	void openInApp() override;
};

class WatchlistHTML : public Watchlist
{
public:
	WatchlistHTML(int capacity) : Watchlist(capacity) {}

	void writeToFile1(string filename) override;
	void openInApp() override;
};
