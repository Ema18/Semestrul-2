//
// Created by Ema on 4/23/2017.
//

#include "../includes/Controller.h"

void Controller::addMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
    Movie m(title, genre, year, likes, trailer, duration);
    this->repo.addMovie(m);
}

int Controller::deleteMovie(const std::string& title)
{
    return this->repo.deleteMovie(title);
}

int Controller::updateMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
    Movie m(title, genre, year, likes, trailer, duration);
    this->repo.updateMovie(m);
}

DynamicVector<Movie> Controller::getAllElems()
{
    return this->repo.getAllElems();
}

void Controller::addMovieToWatchlist(const Movie &movie)
{
    this->watch.add(movie);
}