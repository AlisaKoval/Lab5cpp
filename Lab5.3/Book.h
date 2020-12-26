#pragma once
#include <string>
class Book
{
public:
	Book(std::string name, std::string author, int year);
	std::string getName();
	std::string getAuthor();
	int getYear();
private:
	std::string name;
	std::string author;
	int year;
};

