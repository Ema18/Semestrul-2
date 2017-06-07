//
// Created by Ema on 4/24/2017.
//

#include "Validator.h"
#include <regex>

void Validator::validate_movie(const Movie &mov)
{
	if (mov.getTitle().size() == 0)
		throw std::runtime_error("Length can't be zero.");

	if (mov.getGenre().size() == 0)
		throw std::runtime_error("Length can't be zero.");

	if (mov.getYear() < 1900)
		throw std::runtime_error("Year must be greater than 1900!");

	if (mov.getLikes() < 0)
		throw std::runtime_error("Likes can't be negative!");

	if (!regex_match(mov.getTrailer(), regex("w\{3\}\..*\..*")))
		throw std::runtime_error("Link is invalid!");
}