//
// Created by Ema on 4/23/2017.
//

#include "Repository.h"
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(const Movie& m)
{
	Movie m1{};
	try
	{
		m1 = this->findByTitle(m.getTitle());
		throw DuplicateMovieException();
	}
	catch (InexistentMovieException& e) {}
	this->movies.push_back(m);
	this->writeToFile();
}

void Repository::removeMovie(const Movie& m)
{
	int pos;
	pos = getPosition(m.getTitle());
	if (pos == -1)
		throw InexistentMovieException{};
	this->movies.erase(movies.begin() + pos);
	this->writeToFile();
}

void Repository::updateMovie(const Movie& m)
{
	int pos;
	pos = getPosition(m.getTitle());
	this->movies.erase(movies.begin() + pos);
	this->movies.push_back(m);
}

Movie Repository::findByTitle(const std::string &title)
{
	for (auto m: this->movies)
	{
		if (m.getTitle() == title)
			return m;
	}
	
	throw InexistentMovieException{};
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

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Movie m;
	while (file >> m)
		this->movies.push_back(m);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		file << m;
	}

	file.close();
}