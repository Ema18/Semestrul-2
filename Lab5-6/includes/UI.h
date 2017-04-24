//
// Created by Ema on 4/23/2017.
//

#pragma once
#include "Controller.h"
#include "Watchlist.h"

class UI
{
private:
    Controller ctrl;
	Watchlist wlist;

public:
    UI() {};
	UI(const Controller& c, Watchlist wlist);
    ~UI() {};
	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printWatchlistMenu();
	static void printSuggestionMenu(Movie mov);

    void addMovie();
    void deleteMovie();
    void getAllElems();
    void updateMovie();
	void filterMovies();

	void getSuggestions();
	void printSuggestions();
	void deleteSuggestion();
};

