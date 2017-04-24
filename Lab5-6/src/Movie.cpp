//
// Created by Ema on 4/23/2017.
//

#include <afxres.h>
#include "../includes/Movie.h"

Movie::Movie(): title(""), genre(""), year(0), likes(0), trailer(""), duration(0) {}

Movie::Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer, const int& duration)
{
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->trailer = trailer;
    this->duration = duration;
}

Movie::Movie(const Movie& mov)
{
    this->title = mov.title;
    this->genre = mov.genre;
    this->year = mov.year;
    this->likes = mov.likes;
    this->trailer = mov.trailer;
    this->duration = mov.duration;
}

Movie::~Movie()
{

}

void Movie::start()
{
    ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}