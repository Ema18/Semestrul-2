#include "MovieValidator.h"

using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors } {}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

std::string MovieException::getErrorAsString() const
{
	string err;
	for (auto e : this->errors)
		err += e;
	return err;
}

void MovieValidator::validate(const Movie& m)
{
	vector<string> errors;
	if (m.getTitle().size() < 3)
		errors.push_back("The title name cannot be less than 2 characters!\n");
	if (m.getGenre().size() < 3)
		errors.push_back("The genre cannot be less than 2 characters!\n");
	if (m.getDuration() == 0)
		errors.push_back("The duration cannot be 0!\n");

	int posWww = m.getTrailer().find("www");
	if (posWww != 0)
		errors.push_back("The trailer must start with 'www'!\n");

	if (errors.size() > 0)
		throw MovieException(errors);
}