//
// Created by Ema on 4/23/2017.
//

#include "Repository.h"

using namespace std;

Repository::Repository()
{
	this->movies = vector<Movie>();
	this->validator_class = Validator();
}

void Repository::addMovie(const Movie& m)
{
	validator_class.validate_movie(m);
	this->movies.push_back(m);
	
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

	for (Movie mov : movies)
	{
		if (mov.getTitle() == name)
			return counter;
		counter++;
	}
	return -1;
}

void Repository::loadFromFile(string filename)
{
	ifstream f(filename);
	string temp;
	string *args;
	while (!f.eof())
	{
		getline(f, temp);
		if (f.eof()) break;

		args = splitString(temp);
		this->addMovie(Movie{ args[0], args[1], stoi(args[2]), stoi(args[3]), args[4], stoi(args[5]) });
	}
	f.close();
}