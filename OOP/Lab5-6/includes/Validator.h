//
// Created by Ema on 4/24/2017.
//

#include <exception>
#include <iostream>
#include "../includes/Movie.h"

using namespace std;

#ifndef LAB5_VALIDATOR_H
#define LAB5_VALIDATOR_H

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

#endif //LAB5_VALIDATOR_H
