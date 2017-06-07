//
// Created by Ema on 4/23/2017.
//

#include "Tests.h"
#include <assert.h>
#include "Repository.h"
#include "Watchlist.h"
#include "Controller.h"
#include "Counter.h"
#include <string.h>

void Tests::testMovie()
{
	Movie m{ "Deadpool", "Action", 2016, 90, "www.youtube.com", 200 };
	assert(m.getTitle() == "Deadpool");
	assert(m.getGenre() == "Action");
	assert(m.getYear() == 2016);
	assert(m.getLikes() == 90);
	assert(m.getTrailer() == "www.youtube.com");
	assert(m.getDuration() == 200);
	assert(m.incLikes() == 91);
	assert(m.operator<(100) == false);
	m.start();
	//m.str();
	string s = m.toString();
	//printf("%d ",m.getAlive());
	//printf("%d", m.getTotal());
}

void Tests::testValidator()
{
	Repository repo{};
	bool exc = false;
	Movie m1{ "", "", 1888, -1, "", 150 };
	try
	{
		repo.addMovie(m1);
	}
	catch (std::runtime_error & excep)
	{
		exc = true;
	}
	assert(exc == true);

	exc = false;
	Movie m2{ "Logan", "", 1888, -1, "", 150 };
	try
	{
		repo.addMovie(m2);
	}
	catch (std::runtime_error & excep2)
	{
		exc = true;
	}
	assert(exc == true);

	exc = false;
	Movie m3{ "Logan", "Drama", 1888, -1, "", 150 };
	try
	{
		repo.addMovie(m3);
	}
	catch (std::runtime_error & excep3)
	{
		exc = true;
	}
	assert(exc == true);

	exc = false;
	Movie m4{ "Logan", "Drama", 2017, -1, "", 150 };
	try
	{
		repo.addMovie(m4);
	}
	catch (std::runtime_error & excep4)
	{
		exc = true;
	}
	assert(exc == true);

	exc = false;
	Movie m5{ "Logan", "Drama", 2017, 1, "", 150 };
	try
	{
		repo.addMovie(m5);
	}
	catch (std::runtime_error & excep5)
	{
		exc = true;
	}
	assert(exc == true);
}

void Tests::testRepository()
{
	Repository repo{};
	Movie m{ "Deadpool", "Action", 2016, 90, "www.youtube.com", 200 };
	repo.addMovie(m);
	Movie res = repo.findByTitle("Deadpool");
	assert(res.getTitle() == m.getTitle() && res.getGenre() == m.getGenre());
	res = repo.findByTitle("Logan");
	assert(res.getTitle() == "");
	repo.incLikes("Deadpool");
	int likes = m.incLikes();
	assert(likes == 91);

	vector<Movie> movies = repo.getAllElems();
	assert(movies.size() == 1);

	int pos = repo.getPosition("Deadpool");
	assert(pos == 0);
	pos = repo.getPosition("Logan");
	assert(pos == -1);

	Movie m3{ "Logan", "Drama", 2017, 200, "www.youtube.com", 120 };
	repo.addMovie(m3);
	pos = repo.getPosition("Logan");
	assert(pos == 1);

	Movie m2{ "Deadpool", "Drama", 2000, 1, "www.youtube.com", 150 };
	repo.updateMovie(m2);
	Movie res2 = repo.findByTitle("Deadpool");
	/*
	assert(m2.getTitle() == res2.getTitle());
	assert(m2.getGenre() == res2.getGenre());
	assert(m2.getYear() == res2.getYear());
	assert(m2.getLikes() == res2.getLikes());
	assert(m2.getTrailer == res2.getTrailer());
	assert(m2.getDuration == res2.getDuration());
	*/

	repo.deleteMovie("Deadpool");
	vector<Movie> movies2 = repo.getAllElems();
	assert(movies2.size() == 1);
}

void Tests::testWatchlist()
{
	WatchlistCSV watchlist{ 20 };
	Movie m1{ "Deadpool", "Action", 2016, 90, "www.youtube.com", 200 };
	Movie m2{ "Logan", "Action", 2017, 80, "www.youtube.com", 180 };

	watchlist.add(m1);
	watchlist.add(m2);
	vector<Movie> movies3 = watchlist.getArray();

	assert(watchlist.getPosition("Deadpool") == 0);

	watchlist.del("Deadpool");
	watchlist.del("The dark knight");
	assert(watchlist.getPosition("Deadpool") == -1);

	Repository repo{};
	repo.addMovie(m1);
	repo.addMovie(m2);
	vector<Movie> movies = watchlist.getSuggestions(repo.getAllElems(), "Action");
	vector<Movie> movies2 = watchlist.getSuggestions(repo.getAllElems(), "");
	//assert(movies2 == repo.getAllElems());
}

void Tests::testController()
{
	Repository repo{};
	Controller ctrl2{};
	Controller ctrl{ repo };
	
	//Repository* r = ctrl.getRepo;
	//assert(r == repo); dumb

	ctrl.addMovie("Deadpool", "Action", 2016, 90, "www.youtube.com", 200);
	ctrl.addMovie("Logan", "Action", 2017, 80, "www.youtube.com", 180);
	Movie m{ "Deadpool", "Action", 2016, 90, "www.youtube.com",200 };
	ctrl.addMovieToWatchlist(m);

	assert(ctrl.getRepo().getAllElems().size() == 2);

	/*
	WatchlistCSV list = ctrl.getWatchlist();
	assert(list.getPosition("Deadpool") == 0);
	assert(list.getPosition("The dark knight") == -1);
	ctrl.incLikes("Deadpool");
	ctrl.updateMovie("Deadpool", "Comedy", 2012, 20, "www.youtube.com", 40);
	ctrl.deleteMovie("Deadpool");
	assert(ctrl.getRepo().getAllElems().size() == 1);
	vector<Movie> movies = ctrl.getAllElems();
	assert(movies.size() == 1);
	*/
}

void Tests::testAll()
{
	testMovie();
	testRepository();
	testWatchlist();
	testController();
	testValidator();
}