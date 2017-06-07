//
// Created by Ema on 4/23/2017.
//

#include "../includes/Tests.h"
#include <assert.h>
#include "../includes/DynamicVector.h"
#include "../includes/Repository.h"
#include "../includes/Watchlist.h"
#include "../includes/Controller.h"

void Tests::testMovie()
{
    Movie m{ "Deadpool", "Action", 2016, 90, "www.youtube.com", 200};
    assert(m.getTitle() == "Deadpool");
    assert(m.getGenre() == "Action");
    assert(m.getYear() == 2016);
    assert(m.getLikes() == 90);
    assert(m.getTrailer() == "www.youtube.com");
    assert(m.getDuration() == 200);
}

void Tests::testDynamicVector()
{
    DynamicVector<int> v1{ 2 };
    v1.add(10);
    v1.add(20);
    assert(v1.getSize()  == 2);
    assert(v1[1] == 20);
    v1.add(30);
    assert(v1.getSize() == 3);

    DynamicVector<int> v2 = v1;
    assert(v2.getSize() == 3);

    DynamicVector<int> v3;
    v3 = v1;
    assert(v3[0] == 10);

    /// test iterator
    DynamicVector<int>::iterator it = v1.begin();
    assert(*it == 10);
    assert(it != v1.end());
    it++;
    assert(*it == 20);
}

void Tests::testRepository()
{
    Repository repo{};
    Movie m{ "Deadpool", "Action", 2016, 90, "www.youtube.com", 200};
    repo.addMovie(m);
    Movie res = repo.findByTitle("Deadpool");
    assert(res.getTitle() == m.getTitle() && res.getGenre() == m.getGenre());
    res = repo.findByTitle("Logan");
    assert(res.getTitle() == "");

    vector<Movie> movies = repo.getAllElems();
    assert(movies.size() == 1);
}

void Tests::testWatchlist()
{
    Watchlist watchlist{};
    Movie m1{"Deadpool", "Action", 2016, 90, "www.youtube.com", 200};
    Movie m2{ "Logan", "Action", 2017, 80, "www.youtube.com", 180};

    watchlist.add(m1);
    watchlist.add(m2);

    assert(watchlist.getPosition("Deadpool") == 0);
}

void Tests::testController()
{
    Repository repo{};
    Controller ctrl{ repo };
    ctrl.addMovie("Deadpool", "Action", 2016, 90, "www.youtube.com", 200);
    ctrl.addMovie("Logan", "Action", 2017, 80, "www.youtube.com", 180);
    Movie m{"Deadpool", "Action", 2016, 90, "www.youtube.com",200};
    ctrl.addMovieToWatchlist(m);

    //assert(ctrl.getRepo().getAllElems().getSize() == 2);

    Watchlist list = ctrl.getWatchlist();
    assert(list.getPosition("Deadpool") == 0);
    assert(list.getPosition("The dark knight") == -1);

}

void Tests::testAll()
{
    testMovie();
    testDynamicVector();
    testRepository();
    testWatchlist();
    testController();
}