#pragma once
#include "Book.h"
class BookSorter
{
public:
	BookSorter();
	BookSorter(size_t key);
	bool operator()(Book* b1, Book* b2);
private:
	size_t key;
};

