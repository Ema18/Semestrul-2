//
// Created by Ema on 4/24/2017.
//

#pragma once

#include <exception>
#include <iostream>
#include "Movie.h"

using namespace std;

class Validator : exception
{
public:

	/** Constructor */
	Validator() {}

	/** Function to validate the input data of a movie
	* TODO make it work tho
	* @param mov the movie to be validated
	*/
	void validate_movie(const Movie& mov);
};
