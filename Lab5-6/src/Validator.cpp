//
// Created by Ema on 4/24/2017.
//

#include "../includes/Validator.h"
#include <regex>

void Validator::validate_movie(const Movie &mov)
{
    if (mov.getTitle().size() == 0)
        throw "Length can't be zero.";

    if (mov.getGenre().size() == 0)
        throw "Length can't be zero.";

    if (mov.getYear() < 1900)
        throw "Year must be greater than 1900!";

    if (mov.getLikes() < 0)
        throw "Likes can't be negative!";

    if (!regex_match(mov.getTrailer(), regex("w\{3\}\..*\..*")))
        throw "Link is invalid!";
}