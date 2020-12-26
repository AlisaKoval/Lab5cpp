#include "Book.h"
#include <clocale>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
//���������� ������, ���-2, 4 �������

/*���������� � ������� �� ������� ���������� ���� ���� ����� 2009 ����, ���������
������ ����������� ��������� � �������� STL (���c�����: std::count_if,
std::greater<>, std::bind2nd).*/

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

	std::vector<int> years;//������ � ������ ������� ����
	for (auto& i : books)
		years.push_back(i->getYear());

	std::cout << std::count_if(years.begin(), years.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;
	return 0;
}