#include <iostream>
#include "Book.h"
#include "BookFinder.h"
#include "BookSorter.h"
#include <vector>
#include <algorithm>
//���������� ������, ���-2, 4 �������

/*. ������� ����� ����� Book, � ������� �������� ��������, ����� � ��� ������� �����. �
������� ������� ������� ��������� ���� (���������� �). ������������������
���������� ���� �� ������ (��������� ����) � �������� (��������� ����).
������������������ ����� � ���������: ����� ��� �����, ��� ������� �������
��������� � ��������� ���������. ������������ ��������� std::vector � ��������.*/

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	std::vector<Book*> books;
	books.push_back(new Book("����� � ���", "������� �.�.", 2010));
	books.push_back(new Book("���������", "����������� �.�.", 2004));
	books.push_back(new Book("�����", "�������� �.�.", 2010));
	books.push_back(new Book("���� ��������", "������� �.�.", 1999));
	books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
	books.push_back(new Book("���������� �������", "������� �.", 2009));
	books.push_back(new Book("������ �����", "������� �.", 2001));
	books.push_back(new Book("�����", "ø�� �.�.", 2010));
	books.push_back(new Book("����� ������", "������� �.", 1998));
	std::cout << "\n����� � ���������� �������:\n\n";
	BookSorter book_sorter;
	std::sort(books.begin(), books.end(), book_sorter);
	std::vector<Book*>::iterator i;
	for (i = books.begin(); i != books.end(); ++i)
	{
		std::cout << (*i)->getAuthor() << " \""
			<< (*i)->getName() << "\"" << std::endl;
	}
	BookFinder book_finder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\n����� � ��������� ���� ������� 2005 - 2014:\n\n";
	while (finder != books.end())
	{
	std::cout << (*finder)->getAuthor() << " \""
		<< (*finder)->getName() << "\"" << std::endl;
	finder = std::find_if(++finder, books.end(), book_finder);
	}
	for (i = books.begin(); i != books.end(); ++i)
	{
		delete (*i);
	}
	return 0;
}