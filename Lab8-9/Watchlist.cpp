//
// Created by Ema on 4/23/2017.
//

#include <vector>
#include "Watchlist.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <sstream>

Watchlist::Watchlist(int capacity)
{
	vector<Movie> suggestions = vector<Movie>();
	vector<Movie> movieList = vector<Movie>();
}

void Watchlist::add(const Movie &movie)
{
	this->movieList.push_back(movie);
}

int Watchlist::getPosition(string name)
{
	int counter = 0;
	for (Movie mov : movieList)
	{
		if (mov.getTitle() == name)
			return counter;
		counter++;
	}
	return -1;
}

int Watchlist::del(string title)
{
	int pos = getPosition(title);

	if (pos == -1)
		return 0;
	//TODO: delete pe vector din stl
	this->movieList.erase(movieList.begin() + pos);
	return 1;
}

const vector<Movie> Watchlist::getArray() 
{ 
	return this->movieList; 
}

vector<Movie> Watchlist::getSuggestions(vector<Movie> repo, string needle)
{
	if (needle == "")
		return repo;
	vector<Movie> suggestions = vector<Movie>(10);
	for (int i = 0; i <repo.size(); i++)
	{
		Movie mov = repo[i];
		if (mov.getGenre() == needle)
			suggestions.push_back(mov);
	}
	return suggestions;
}


void WatchlistCSV::writeToFile1(string filename)
{
	ofstream g(filename);
	for (Movie mov : movieList)
	{
		g << mov.toString();
	}
	g.close();
}

void WatchlistCSV::openInApp()
{
	//system("open C:\\Users\\Ema\\Documents\\Visual Studio 2015\\Projects\\Lab8-9v2\\Lab8-9v2\\Movies.csv");
	stringstream s;
	s << "\"" << "C:\\Users\\Ema\\Documents\\Visual Studio 2015\\Projects\\Lab8-9v2\\Lab8-9v2\\Movies.csv" << "\"";
	std::string s2 = s.str();
	ShellExecuteA(NULL, NULL, "notepad.exe", s2.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void WatchlistHTML::writeToFile1(string filename)
{
	ofstream f;
	f.open(filename, ios::out); //(filename);
	cout << f.is_open() << endl;
	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Playlist</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border=\"1\">" << endl;
	//header
	f << "<tr>" << endl;
	f << "<td>Title</td>" << endl; f << "<td>Genre</td>" << endl; f << "<td>Year</td>" << endl; f << "<td>Likes</td>" << endl; f << "<td>Trailer</td>" << endl;
	f << "</tr>" << endl;
	for (Movie mov : this->movieList)
	{
		f << "<tr>" << endl;
		f << "<td>" << mov.getTitle() << "</td>" << endl;
		f << "<td>" << mov.getGenre() << "</td>" << endl;
		f << "<td>" << mov.getYear() << "</td>" << endl;
		f << "<td>" << mov.getLikes() << "</td>" << endl;
		f << "<td><a href =" << mov.getTrailer() << ">Link</a></td>";
		f << "</tr>" << endl;
	}
	f << "</table>" << endl;
	f << "</body>" << endl;
	f << "</html>" << endl;

	f.close();
}

void WatchlistHTML::openInApp()
{
	//system("open C:\\Users\\Ema\\Documents\\Visual Studio 2015\\Projects\\Lab8-9v2\\Lab8-9v2\\Movies.html");
	stringstream s;
	s << "\"" << "C:\\Users\\Ema\\Documents\\Visual Studio 2015\\Projects\\Lab8-9v2\\Lab8-9v2\\Movies.html" << "\"";
	std::string s2 = s.str();
	ShellExecuteA(NULL, NULL, "chrome.exe", s2.c_str(), NULL, SW_SHOWMAXIMIZED);
}