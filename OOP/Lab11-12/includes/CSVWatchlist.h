#pragma once
#include "FileWatchlist.h"
#include <string>

class CSVWatchlist : public FileWatchlist
{
public:
	/*
		Writes the watchlist to file.
		Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
		Displays the watchlist using Excel.
	*/
	void displayWatchlist() const override;
};