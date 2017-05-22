//
// Created by Ema on 4/23/2017.
//

#pragma once

#include <vector>
#include "Movie.h"
#include "Validator.h"
#include <fstream>

using namespace std;

class Repository
{
private:
	vector<Movie> movies;
	Validator validator_class;

public:
	/**
	Default constructor.
	Initializes and object of type Repository
	**/
	Repository();

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
	void deleteMovie(std::string title);

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
	vector<Movie> getAllElems();

	/** Increments the number of likes */
	void incLikes(std::string title) { this->movies[getPosition(title)].incLikes(); }

	/** Writes to file */
	void writeToFile(string filename)
	{
		ofstream f(filename);
		vector<Movie> to_write = this->getAllElems();
		for (Movie mov : to_write)
		{
			f << mov.toString();
		}
		f.close();
	}

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

	void loadFromFile(string filename);

	/** Destructor */
	~Repository() {}

};
