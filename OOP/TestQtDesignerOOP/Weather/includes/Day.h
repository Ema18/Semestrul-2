#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Day
{
public:
	int start;
	int end;
	int temperature;
	int precipitation;
	string description;

public:
	Day() {};
	~Day() {};

	Day(string lsv)
	{
		stringstream ss;
		string s;

		ss << lsv;

		vector<string> args;
		while (getline(ss, s, ';'))
		{
			args.push_back(s);
		}

		start = stoi(args[0]);
		end = stoi(args[1]);
		temperature = stoi(args[2]);
		precipitation = stoi(args[3]);
		description = args[4];
	}
};