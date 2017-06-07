#include "Utils.h"
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string trim(const string& s)
{
	string result(s);
	int pos = result.find_first_not_of(" ");
	if (pos != -1)
		result.erase(0, pos);
	pos = result.find_last_not_of(" ");
	if (pos != string::npos)
		result.erase(pos + 1);

	return result;
}

vector<string> tokensize(const string& str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}