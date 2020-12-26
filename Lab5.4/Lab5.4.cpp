#include "Book.h"
#include <clocale>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
//Криворучко Ксения, ИВТ-2, 4 вариант

/*Подсчитать и вывести на консоль количество всех книг новее 2009 года, используя
только стандартные алгоритмы и функторы STL (подcказка: std::count_if,
std::greater<>, std::bind2nd).*/

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	std::vector<Book*> books;
	books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
	books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));

	std::vector<int> years;//вектор с годами выпуска книг
	for (auto& i : books)
		years.push_back(i->getYear());

	std::cout << std::count_if(years.begin(), years.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;
	return 0;
}