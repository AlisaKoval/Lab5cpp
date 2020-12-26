#include "Book.h"
#include <string>
Book::Book(std::string _name, std::string _author, int _year)
{
	name = _name;
	author = _author;
	year = _year;
}
std::string Book::getName()
{
	return name;
}
std::string Book::getAuthor()
{
	return author;
}
int Book::getYear()
{
	return year;
}