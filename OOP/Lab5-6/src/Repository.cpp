//
// Created by Ema on 4/23/2017.
//

#include "../includes/Repository.h"

using namespace std;

Repository::Repository()
{
    this->movies = vector<Movie>();
    this->validator_class = Validator();
}

void Repository::addMovie(const Movie& m)
{
    try
    {//validator_class.validate_movie(m);
    this->movies.push_back(m);
    }
    catch (string exc)
    {
        cout << exc << endl;
    }

}

void Repository::deleteMovie(string title)
{
    int pos;
    pos = getPosition(title);
    this->movies.erase(movies.begin() + pos);
}

void Repository::updateMovie(const Movie& m)
{
    int pos;
    pos = getPosition(m.getTitle());
    this->movies.erase(movies.begin() + pos);
    this->movies.push_back(m);
}

vector<Movie> Repository::getAllElems()
{
    return this->movies;
}

Movie Repository::findByTitle(const std::string &title)
{
    for (int i = 0; i < this->movies.size(); i++)
    {
        Movie m = movies[i];
        if (m.getTitle() == title)
            return m;
    }
    return Movie{};
}

int Repository::getPosition(const string& name)

{
    int counter = 0;

    for (Movie mov: movies)
    {
        if (mov.getTitle() == name)
            return counter;
        counter++;
    }
    return -1;
}