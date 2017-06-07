//
// Created by Ema on 4/23/2017.
//

#pragma once

#include <vector>
#include "Movie.h"
#include <fstream>

using namespace std;

class Repository
{
private:
	vector<Movie> movies;
	string filename;

public:
	/**
	Default constructor.
	Initializes and object of type Repository
	**/
	Repository(const string& filename);

	/**
	Adds a movie to the repository
	Input: m - Movie
	Output: the movie is added to the repo
	**/
	void addMovie(const Movie& m);

	/**
	Deletes a movie from the repository
	Input: title of the movie to be deleted
	Output: the movie, if found is deleted from the repo
	**/
	//void deleteMovie(std::string title);
	void removeMovie(const Movie& m);

	/**
	* Updates a movie from the repository
	* @param m the movie to be updated
	*/
	void updateMovie(const Movie& m);

	/**
	* Search for a movie using its title
	* @param title - the title of the movie
	*/
	Movie findByTitle(const std::string& title);

	/**
	* Get the position of a movie in the repository.
	* @param name - title of the movie
	* @return pos - the position in the repository if it is found, 0 otherwise
	*/
	int getPosition(const std::string& name);

	/** Get all the elements from the repository */
	vector<Movie> getMovies() const { return movies; }

	/** Increments the number of likes */
	void incLikes(std::string title) { this->movies[getPosition(title)].incLikes(); }

	string *splitString(string temp)
	{
		string *args = new string[6];
		stringstream ss(temp);
		string token;
		int i = 0;

		while (getline(ss, token, ','))
			args[i++] = token;
		return args;
	}

	/** Destructor */
	~Repository() {}

private:
	void readFromFile();
	void writeToFile();

};
