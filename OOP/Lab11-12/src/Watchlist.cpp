//
// Created by Ema on 4/23/2017.
//

#include <vector>
#include "Watchlist.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <sstream>

Watchlist::Watchlist(int capacity)
{
	vector<Movie> suggestions = vector<Movie>();
	vector<Movie> movies = vector<Movie>();
}

void Watchlist::add(const Movie &movie)
{
	this->movies.push_back(movie);
}

int Watchlist::getPosition(string name)
{
	int counter = 0;
	for (Movie mov : movies)
	{
		if (mov.getTitle() == name)
			return counter;
		counter++;
	}
	return -1;
}

int Watchlist::del(string title)
{
	int pos = getPosition(title);

	if (pos == -1)
		return 0;
	this->movies.erase(movies.begin() + pos);
	return 1;
}

vector<Movie> Watchlist::getSuggestions(vector<Movie> repo, string needle)
{
	if (needle == "")
		return repo;
	vector<Movie> suggestions = vector<Movie>(10);
	for (int i = 0; i <repo.size(); i++)
	{
		Movie mov = repo[i];
		if (mov.getGenre() == needle)
			suggestions.push_back(mov);
	}
	return suggestions;
}