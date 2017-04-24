//
// Created by Ema on 4/23/2017.
//

#include "includes/Movie.h"
#include "includes/UI.h"
#include "includes/Tests.h"

using namespace std;

int main()
{
    /** testing */
    Tests::testAll();

    cout << endl;
    cout << "Created & alive after testing: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;

    /** starting the app */
    Repository* repo = new Repository{};
    Watchlist* user_repo = new Watchlist{30};
    Controller* ctrl = new Controller{*repo};
    UI* ui = new UI{*ctrl, *user_repo};

    cout << "Created & alive after initializing: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;

    ui->run();

    delete ui;
    delete ctrl;
    delete user_repo;
    delete repo;

    cout << "Created & alive after exiting: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;

    return 0;
}
