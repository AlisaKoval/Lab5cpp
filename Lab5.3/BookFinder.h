#pragma once
#include "Book.h"
class BookFinder
{
public:
	BookFinder(int l, int r);
	bool operator()(Book* b);
private:
	int l;
	int r;
};

