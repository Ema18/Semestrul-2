#pragma once
#include "FileRepository.h"
#include <algorithm>

using namespace std;

class Controller
{
private:
	FileRepository repo;

public:
	Controller(FileRepository repo)
		: repo{ repo } {};


	/*
		method that filters the list by precipitation less than a given value
		args: value - the maximum precipitation
		return: a new vector with all the filtered options
	*/
	vector<Day> filter_repo(string value)
	{
		vector<Day> filter;
		for (Day d : get_all())
			if (d.precipitation < stoi(value))
				filter.push_back(d);
		return filter;
	}

	/* 
		method that computes the total number of hours with a given description
		args: description - the given description of the weather
		return: the total number of hours
	*/
	int count_hours(string description)
	{
		int nr = 0;
		for (Day d : get_all())
			if (d.description == description)
				nr += d.end - d.start;
		return nr;
	}

	vector<Day>& get_all()
	{
		return repo.get_all();
	}

};