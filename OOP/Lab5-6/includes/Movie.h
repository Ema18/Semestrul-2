//
// Created by Ema on 4/23/2017.
//

#pragma once
#include <iostream>
#include "../includes/Counter.h"
#include <string>
#include <sstream>

using namespace std;

class Movie : private Counter<Movie>
{
private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;
    int duration;

public:
    using Counter<Movie>::getTotal;
    using Counter<Movie>::getAlive;

    /** Constructors */
    Movie();
    Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration);
    Movie(const Movie& mov);

    /** Getters for all the parameters of an object of type Movie */
    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
    int getYear() const { return year; }
    int getLikes() const { return likes; }
    std::string getTrailer() const { return trailer; }
    int getDuration() const { return duration; }

    /** Destructor */
    ~Movie();

    /** Starts the trailer: the page corresponding to the source link is opened in a browser. */
    void start();

    /** Displays nicely an object of type Movie. */
    void str() {std::cout << "Title: " << this->getTitle() << ", Genre: " << this->getGenre() << ", Year: " << this->getYear()
                     << ", No. of likes: " << this->getLikes() << ", Trailer link: " << this->getTrailer() << ", Duration: " << this->getDuration() << "\n"; }

    /** Display in a file */
    string toString()
    {
        stringstream s;
        s << title << ", " << genre << ", " << year << ", " << likes << ", " << trailer << ", " << duration << "\n";
        return s.str();
    }

    /** Increments the likes for the option 2 at the user mode .*/
    int incLikes() { this->likes++; return this->likes;}

    /** Overload operator < */
    bool operator<(int other) { return this->getDuration() < other; }
};
