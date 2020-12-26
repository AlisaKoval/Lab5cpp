#include "BookFinder.h"
BookFinder::BookFinder(int _l, int _r)
{
	l = _l;
	r = _r;
}
bool BookFinder::operator()(Book* b)
{
	return b->getYear() >= l && b->getYear() <= r;
}