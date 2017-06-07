//
// Created by Ema on 4/23/2017.
//

#include "Controller.h"

using namespace std;

void Controller::addMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
	Movie m(title, genre, year, likes, trailer, duration);
	this->repo.addMovie(m);
	this->repo.writeToFile("data.txt");
}

void Controller::deleteMovie(const std::string& title)
{
	this->repo.deleteMovie(title);
	this->repo.writeToFile("data.txt");
}

void Controller::updateMovie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
	Movie m(title, genre, year, likes, trailer, duration);
	this->repo.updateMovie(m);
	this->repo.writeToFile("data.txt");
}

vector<Movie> Controller::getAllElems()
{
	return this->repo.getAllElems();
}

void Controller::addMovieToWatchlist(const Movie &movie)
{
	//this->watch.add(movie);
}