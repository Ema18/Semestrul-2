//
// Created by Ema on 4/23/2017.
//

#include "../includes/Watchlist.h"

Watchlist::Watchlist(int capacity)
{
    DynamicVector<Movie> suggestions = DynamicVector<Movie>(10);
}

void Watchlist::add(const Movie &movie)
{
    this->movieList.add(movie);
}

int Watchlist::getPosition(string name)
{
    int counter = 0;
    for ( Movie mov: movieList)
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
    std::string title2 = this->movieList[pos].getTitle();
    this->movieList.deleteMovie(title2);
    return 1;
}

DynamicVector<Movie> Watchlist::getSuggestions(DynamicVector<Movie> repo, string needle)
{
    if (needle == "")
        return repo;
    DynamicVector<Movie> suggestions = DynamicVector<Movie>(10);
    for (int i = 0; i < repo.getSize(); i++)
    {
        Movie mov = repo[i];
        if (mov.getGenre() == needle)
            suggestions.add(mov);
    }
    return suggestions;
}
