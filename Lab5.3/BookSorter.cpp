#include "BookSorter.h"
BookSorter::BookSorter()
{
	key = 2;
}
BookSorter::BookSorter(size_t _key)
{
	key = _key;
}
bool BookSorter::operator()(Book* b1, Book* b2)
{
	if (key == 1)
		return b1->getAuthor() < b2->getAuthor();
	return b1->getName() < b2->getName();
}