//
// Created by Ema on 4/23/2017.
//

#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include "Movie.h"

Movie::Movie() : title(""), genre(""), year(0), likes(0), trailer(""), duration(0) {}

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

bool Movie::operator==(const Movie& m)
{
	return (this->title == m.title && this->genre == m.title);
}

istream & operator >> (istream & is, Movie & m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokensize(line, ',');
	if (tokens.size() != 6)
		return is;

	m.title = tokens[0];
	m.genre = tokens[1];
	m.year = stoi(tokens[2]);
	m.likes = stoi(tokens[3]);
	m.trailer = tokens[4];
	m.duration = stoi(tokens[5]);

	return is;
}

ostream & operator<<(ostream & os, const Movie & m)
{
	os << m.title << "," << m.genre << "," << m.year << "," << m.likes << "," << m.trailer << "," << m.duration << "\n";
	return os;
}