//
// Created by Ema on 4/23/2017.
//

#include "DynamicVector.h"
#include "Movie.h"

using namespace std;

#ifndef LAB5_WATCHLIST_H
#define LAB5_WATCHLIST_H

class Watchlist
{
private:
    DynamicVector<Movie> movieList;

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
    DynamicVector<Movie> getSuggestions(DynamicVector <Movie> repo, string needle);

    /** Getter for the Watchlist */
    DynamicVector<Movie> getArray() { return this->movieList; }

    /** Get the position of a movie in the watchlist, searching by its title */
    int getPosition(string name);
};

#endif //LAB5_WATCHLIST_H
