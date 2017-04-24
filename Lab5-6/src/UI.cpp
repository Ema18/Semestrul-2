//
// Created by Ema on 4/23/2017.
//

#include "../includes/UI.h"
#include <string>

using namespace std;

UI::UI(const Controller &c, Watchlist wlist)
{
    this->ctrl = c;
    this->wlist = wlist;
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage movie repository."<<endl;
	cout << "2 - Manage watchlist." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Delete movie." << endl;
	cout << "\t 4 - Update movie." << endl;
    cout << "\t 5 - Filter movies." << endl;
 	cout << "\t 0 - Back." << endl;
}

void UI::printWatchlistMenu()
{
    cout << "Possible commands: " << endl;
    cout << "\t 1 - Get movie suggestions." << endl;
    cout << "\t 2 - Delete watched movie." << endl;
    cout << "\t 3 - Display watchlist." << endl;
    cout << "\t 0 - Back." << endl;
}

void UI::printSuggestionMenu(Movie mov)
{
    cout << mov.getTitle() << endl;
    cout << "1 - Watch trailer" << endl;
    cout << "2 - Add to watchlist" << endl;
    cout << "3 - Skip" << endl;
    cout << "0 - Back" << endl;
}

void UI::addMovie()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
    while (this->ctrl.getRepo().getPosition(title) != -1)
    {
        cout << "Movie already exists in the repository." << endl;
        cout << "Enter another title: " << endl;
        getline(cin, title);
    }
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin>>year;
	cin.ignore();
	//getline(cin, year);
	cout << "Enter the number of likes: ";
	int likes;
	//getline(cin, likes);
	cin>>likes;
	cin.ignore();
	cout << "Trailer link: ";
	std::string trailer;
	getline(cin, trailer);
    cout << "Duration of the movie: ";
    int duration;
    cin >> duration;
    cin.ignore();

	this->ctrl.addMovie(title, genre, year, likes, trailer, duration);
}

void UI::deleteMovie()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);

	if (this->ctrl.deleteMovie(title) == 0)
        cout << "The movie doesn't exist.";
    else
        cout << "Movie deleted!"; // this->ctrl.deleteMovie(title);
}

void UI::updateMovie()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin>>year;
	cin.ignore();
	//getline(cin, year);
	cout << "Enter the number of likes: ";
	int likes;
	//getline(cin, likes);
	cin>>likes;
	cin.ignore();
	cout << "Trailer link: ";
	std::string trailer;
	getline(cin, trailer);
    cout << "Duration of the movie: ";
    int duration;
    cin>>duration;
    cin.ignore();

	if (this->ctrl.updateMovie(title, genre, year, likes, trailer, duration) == -1)
        cout << "The movie doesn't exist.\n";
    else
        this->ctrl.updateMovie(title, genre, year, likes, trailer, duration);
}

void UI::getAllElems()
{
	DynamicVector<Movie> v = this->ctrl.getAllElems();
	Movie* movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Movie m = movies[i];
		cout << "Title: " << m.getTitle() << ", Genre: " << m.getGenre() << ", Year: " << m.getYear() << ", Likes: " << m.getLikes() << ", Duration: " << m.getDuration() << endl;
	}
}
/**
void UI::addMovieToWatchlist()
{
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);

    ///search for the movie in the repository
    Movie m = this->ctrl.getRepo().findByTitle(title);
    if (m.getTitle() == "")
    {
        cout << "There are no movies with the given data in the repository. Nothing to add.";
        return;
    }

    this->ctrl.addMovieToWatchlist(m);
}
*/

void UI::filterMovies()
{
    DynamicVector<Movie> filtered;
    DynamicVector<Movie> movies;
    cout << "Input value: " << endl;
    int other;
    cin >> other;
    cin.ignore();

    movies = this->ctrl.getAllElems();
    if (movies.getSize() == 0)
        cout << "No movies to filter." << endl;
    else
    {
        for (int i = 0; i < movies.getSize(); i++)
        {
            if (movies[i] < other)
                filtered.add(movies[i]);
        }
    }

    for (int i = 0; i < filtered.getSize(); i++)
        filtered[i].str();
}

void UI::getSuggestions()
{
    std::string needle;
    DynamicVector<Movie> suggestions;
    cout << "Input genre: (press Enter for all suggestions)" << endl;
    getline(cin, needle);

    suggestions = this->wlist.getSuggestions(this->ctrl.getAllElems(), needle);
    if (suggestions.getSize() == 0)
        cout << "No suggestions for this genre, sorry!";
    else
    {
        for (int i = 0; i < suggestions.getSize(); i++)
        {
            int command{0};
            Movie mov = suggestions[i];
            do
            {
                printSuggestionMenu(mov);
                cout << "Input the command: ";
                cin >> command;
                cin.ignore();
            }while (command < 1 && command > 3);
            if (command == 1)
            {
                mov.start();
            }
            else if (command == 2)
            {
                this->wlist.add(mov);
                if (i+1 == suggestions.getSize())
                    i = -1;
                std::string title = mov.getTitle();
                suggestions.deleteMovie(title);
            }
            else if (command == 3)
            {
                if (i+1 == suggestions.getSize())
                    i = -1;
            }
            else if (command == 0)
                i = suggestions.getSize();
        }
    }

    if (suggestions.getSize() == 0)
        cout << "That's all for now!" << endl;
}

void UI::deleteSuggestion()
{
    cout << "Input title: ";
    std::string title;
    getline(cin, title);

    if (this->wlist.del(title) == 0)
        cout << "The movie does not exist." << endl;
    else
    {
        cout << "Liked the movie? yes/no" << endl;
        std::string like;

        do
        {
            getline(cin, like);
            if (like != "yes" && like != "no")
                cout << "Invalid option" << endl;
        }while(like != "yes" && like != "no");

        if (like == "yes")
        {
            this->ctrl.incLikes(title);
        }
        this->wlist.del(title);
    }
}

void UI::printSuggestions()
{
    int length = this->wlist.getArray().getSize();

    if (length == 0)
        cout << "There are no movies yet." << endl;
    else
    {
        cout << "The movies are:" << endl;
        for (int i = 0; i < length; i++)
        {
            Movie mov = this->wlist.getArray()[i];
            mov.str();
        }
    }
}

void UI::run()
{
    this->ctrl.addMovie("Lord of the Rings", "Fantasy", 1998, 2, "www.youtube.com", 200);
    this->ctrl.addMovie("The Dark Knight", "Action", 2008, 10, "www.youtube.com", 180);
    this->ctrl.addMovie("Fight Club", "Drama", 1999, 20, "www.youtube.com", 100);
    this->ctrl.addMovie("Life is beautiful", "Drama", 1997, 100, "www.youtube.com", 120);
    this->ctrl.addMovie("Saving Private Ryan", "Drama", 1998, 50, "www.youtube.com", 300);
    this->ctrl.addMovie("Suicide Squad", "Action", 2016, 30, "www.youtube.com", 90);
    this->ctrl.addMovie("Doctor Strange", "Fantasy", 2016, 40, "www.youtube.com",110);
    this->ctrl.addMovie("Deadpool", "Action", 2016, 80, "www.youtube.com", 125);
    this->ctrl.addMovie("Logan", "Action", 2017, 90, "www.youtube.com", 130);
    this->ctrl.addMovie("Star Wars - A New Hope", "Action", 1977, 100, "www.youtube.com", 210);

    while (true)
    {
        try {

            UI::printMenu();
            int command{0};
            cout << "Input the command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;

            ///repository management
            if (command == 1) {
                while (true) {
                    UI::printRepositoryMenu();
                    int commandRepo{0};
                    cout << "Input the command: ";
                    cin >> commandRepo;
                    cin.ignore();
                    if (commandRepo == 0)
                        break;
                    switch (commandRepo) {
                        case 1:
                            this->addMovie();
                            break;
                        case 2:
                            this->getAllElems();
                            break;
                        case 3:
                            this->deleteMovie();
                            break;
                        case 4:
                            this->updateMovie();
                            break;
                        case 5:
                            this->filterMovies();
                            break;
                        case 0:
                            break;
                    }
                }
            }

            /// watchlist management
            if (command == 2) {
                while (true) {
                    UI::printWatchlistMenu();
                    int commandWatchlist{0};
                    cout << "Input the command: ";
                    cin >> commandWatchlist;
                    cin.ignore();
                    if (commandWatchlist == 0)
                        break;
                    switch (commandWatchlist) {
                        case 1:
                            this->getSuggestions();
                            break;
                        case 2:
                            this->deleteSuggestion();
                            break;
                        case 3:
                            this->printSuggestions();
                            break;
                        case 0:
                            break;
                    }
                }
            }
        }
        catch (string exc)
        {
            cout << exc << endl;
        }
    }
}
