#pragma once

#include "Day.h"
#include <fstream>

class FileRepository
{
private:
	vector<Day> container;
	string file_name;
	
public:
	FileRepository(string _file_name) : file_name(_file_name)
	{
		read_from_file();
	};

	void read_from_file()
	{
		ifstream f(file_name);
		string lsv;
		while (getline(f, lsv))
		{
			container.push_back(Day{ lsv });
		}

		f.close();
	}

	vector<Day>& get_all()
	{
		return container;
	}
};