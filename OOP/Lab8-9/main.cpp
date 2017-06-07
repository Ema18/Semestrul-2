//
// Created by Ema on 4/23/2017.
//

#include "Movie.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>

using namespace std;

int main()
{
	// testing 
	Tests::testAll();

	cout << endl;
	cout << "Created & alive after testing: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;

	// starting the app 
	Repository* repo = new Repository{};
	repo->loadFromFile("data.txt");
	cout << "What type of file?\n";
	cout << "\t 1. CSV\n";
	cout << "\t 2. HTML\n";

	int command{ 0 };
	cout << "Input the command: ";
	cin >> command;
	cin.ignore();

	while (command != 1 && command != 2)
	{
		cout << "Input 1 or 2" << endl;
		cin >> command;
		cin.ignore();
	}

	Watchlist* user_repo = new WatchlistCSV{ 0 };
	if (command == 1)
		user_repo = new WatchlistCSV{ 30 };
	else if (command == 2)
		user_repo = new WatchlistHTML{ 30 };
	Controller* ctrl = new Controller{ *repo };
	UI* ui = new UI{ *ctrl, user_repo };

	cout << "Created & alive after initializing: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;

	ui->run();

	delete ui;
	delete ctrl;
	delete user_repo;
	delete repo;

	cout << "Created & alive after exiting: " << Counter<Movie>::getTotal() << " " << Counter<Movie>::getAlive() << endl;
	
	return 0;
}
