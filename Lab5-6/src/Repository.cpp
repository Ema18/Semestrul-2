//
// Created by Ema on 4/23/2017.
//

#include "../includes/Repository.h"

using namespace std;

Repository::Repository()
{
    this->movies = DynamicVector<Movie>();
    this->validator_class = Validator();
}

void Repository::addMovie(const Movie& m)
{
    try
    {//validator_class.validate_movie(m);
    this->movies.add(m);
    }
    catch (string exc)
    {
        cout << exc << endl;
    }

}

int Repository::deleteMovie(string title)
{
    return this->movies.deleteMovie(title);
}

int Repository::updateMovie(const Movie& m)
{
    this->movies.update(m);
}

DynamicVector<Movie> Repository::getAllElems()
{
    return this->movies;
}

Movie Repository::findByTitle(const std::string &title)
{
    for (int i = 0; i < this->movies.getSize(); i++)
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