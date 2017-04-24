//
// Created by Ema on 4/23/2017.
//

#pragma once
#include "Movie.h"
#include "DynamicVector.h"
#include "Validator.h"

class Repository
{
private:
    DynamicVector<Movie> movies;
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
    int deleteMovie(std::string title);

    /**
     * Updates a movie from the repository
     * @param m the movie to be updated
     * @return 1 if the movie is found in the repo, 0 otherwise
     */
    int updateMovie(const Movie& m);

    /**
     * Search for a movie using its title
     * @param title - the title of the movie
     * @return the movie if found, or an empty constructor of Movie otherwise
     */
    Movie findByTitle(const std::string& title);

    /**
     * Get the position of a movie in the repository.
     * @param name - title of the movie
     * @return pos - the position in the repository if it is found, 0 otherwise
     */
    int getPosition(const std::string& name);

    /** Get all the elements from the repository */
    DynamicVector<Movie> getAllElems();

    /** Increments the number of likes */
    void incLikes(std::string title) { this->movies[getPosition(title)].incLikes(); }

    /** Destructor */
    ~Repository() {}

};
