#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
template <typename T>
class DataManager
{
public:
	DataManager()
	{
		array = new T[64];
	}
	~DataManager()
	{
		delete[] array;
	}
	void push(T elem)
	{
		if (count == 64)//���� �������� �� 100%
		{
			std::ofstream file("dump.dat", std::ios::app);
			for (size_t i = 0; i < count; i++)
			{
				file << array[i] << "\n";//��������� � ���� ���������
				sizeFile++;//���������� ���������� ���������, ����������� � ����
			}

			file.close();
			count = 0;//����������� ������� ����������
		}
		array[count] = elem;//��������� �������
		count++;//���������� ���������� ���������

	}
	void push(T elems[], size_t n)
	{
		for (size_t i = 0; i < n; i++)
			push(elems[i]);
	}
	T peek()
	{
		if (count < 2)
			return 0;//���� ��������� ������ 2, ���������� 0
		else
			return array[0];//���������� ������ �������
	}
	T pop()
	{
		T cmp = array[0];//���������� ������ ������� �� ��������� ����������
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//������� ��� �������� ����� �� 1
		size_t i = 0;
		if (count == 64)//���� ��� ���������� ������������ ��������� ����� 
		{
			T* mas = new T [sizeFile];//������� ������, ���� ������� ��� ��������
			std::ifstream ifile("dump.dat");	//����� ��� ������	
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//��������� ����� � ������� �������� ������ ������� �� �����
				count++;
				
				while (getline(ifile, line)&&i<sizeFile)
				{
					mas[i] = atoi(line.c_str());//��� ������ �����, ����� �������, ���������� � ������
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//����� ��� ������
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//�������������� � ���� ��� �������� �������, � ������� ��������� ��� ������, ����� ������(���� ������� �������� � ����� ������� ��������� ������)
			offile.close();
			delete[] mas;//������� ��������� ������
		}
		count--;//��������� ��, ��� �� ��������� ���� �������
		return cmp;
	}
	void print()
	{
		std::copy(array, array + count, std::ostream_iterator<T>(std::cout, " "));
		std::cout << "\n";

	}
private:
	T* array;
	size_t count = 0;//���������� ��������� � �������
	size_t sizeFile = 0;//���������� ��������� � �����
};
template<>
class DataManager<char>
{
public:
	DataManager()
	{
		array = new char[64];
	}
	~DataManager()
	{
		delete[] array;
	}
	void push(char elem)
	{
		if (!isalnum(elem))//���� ����������� ������ �� ����� ��� �������, �� �������� ��� �� _
			elem = '_';
		if (count == 64)//���� �������� �� 100%
		{
			std::ofstream file("dump.dat", std::ios::app);
			for (size_t i = 0; i < count; i++)
			{
				file << array[i] << "\n";//��������� � ���� ���������
				sizeFile++;//���������� ���������� ���������, ����������� � ����
			}

			file.close();
			count = 0;//����������� ������� ����������
		}
		array[count] = elem;//��������� �������
		count++;//���������� ���������� ���������
	}
	char popUpper()
	{
		char cmp = array[0];//���������� ������ ������� �� ��������� ����������
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//������� ��� �������� ����� �� 1
		size_t i = 0;
		if (count == 64)//���� ��� ���������� ������������ ��������� ����� 
		{
			char* mas = new char[sizeFile];//������� ������, ���� ������� ��� ��������
			std::ifstream ifile("dump.dat");//����� ��� ������
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//��������� ����� � ������� �������� ������ ������� �� �����
				count++;

				while (getline(ifile, line) && i < sizeFile)
				{
					mas[i] = atoi(line.c_str());//��� ������ �����, ����� �������, ���������� � ������
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//����� ��� ������
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//�������������� � ���� ��� �������� �������, � ������� ��������� ��� ������, ����� ������(���� ������� �������� � ����� ������� ��������� ������)
			offile.close();
			delete[] mas;//������� ��������� ������
		}
		count--;//��������� ��, ��� �� ��������� ���� �������
		return toupper(cmp);
	}
	char popLower()
	{
		char cmp = array[0];//���������� ������ ������� �� ��������� ����������
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//������� ��� �������� ����� �� 1
		size_t i = 0;
		if (count == 64)//���� ��� ���������� ������������ ��������� �����
		{
			char* mas = new char[sizeFile];//������� ������, ���� ������� ��� ��������
			std::ifstream ifile("dump.dat");//����� ��� ������
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//��������� ����� � ������� �������� ������ ������� �� �����
				count++;

				while (getline(ifile, line) && i < sizeFile)
				{
					mas[i] = atoi(line.c_str());//��� ������ �����, ����� �������, ���������� � ������
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//����� ��� ������
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//�������������� � ���� ��� �������� �������, � ������� ��������� ��� ������, ����� ������(���� ������� �������� � ����� ������� ��������� ������)
			offile.close();
			delete[] mas;//������� ��������� ������
		}
		count--;//��������� ��, ��� �� ��������� ���� �������
		return tolower(cmp);
	}
	void print()
	{
		std::copy(array, array + count, std::ostream_iterator<char>(std::cout, " "));
		std::cout << "\n";
	}
private:
	char* array;
	size_t count = 0;//���������� ��������� � �������
	size_t sizeFile = 0;//���������� ��������� � �����
};
