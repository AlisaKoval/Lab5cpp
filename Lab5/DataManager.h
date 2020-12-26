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
		if (count == 64)//если заполнен на 100%
		{
			std::ofstream file("dump.dat", std::ios::app);
			for (size_t i = 0; i < count; i++)
			{
				file << array[i] << "\n";//выгружаем в файл полностью
				sizeFile++;//наращиваем количество элементов, выгруженных в файл
			}

			file.close();
			count = 0;//заполнеение массива обнуляется
		}
		array[count] = elem;//добавляем элемент
		count++;//наращиваем количество элементов

	}
	void push(T elems[], size_t n)
	{
		for (size_t i = 0; i < n; i++)
			push(elems[i]);
	}
	T peek()
	{
		if (count < 2)
			return 0;//если элементов меньше 2, возвращаем 0
		else
			return array[0];//возвращаем первый элемент
	}
	T pop()
	{
		T cmp = array[0];//запоминаем первый элемент во временную переменную
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//смещаем все элементы влево на 1
		size_t i = 0;
		if (count == 64)//если при извлечении освободилось последнее место 
		{
			T* mas = new T [sizeFile];//создаем массив, куда запишем все элементы
			std::ifstream ifile("dump.dat");	//поток для чтения	
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//последнее место в массиве занимает первый элемент из файла
				count++;
				
				while (getline(ifile, line)&&i<sizeFile)
				{
					mas[i] = atoi(line.c_str());//все строки файла, кроме первого, записываем в массив
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//поток для записи
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//перезаписываем в файл все элементы массива, в котором хранились все строки, кроме первой(этот элемент добавили в конец массива элементов класса)
			offile.close();
			delete[] mas;//удаляем временный массив
		}
		count--;//фиксируем то, что мы изввлекли один элемент
		return cmp;
	}
	void print()
	{
		std::copy(array, array + count, std::ostream_iterator<T>(std::cout, " "));
		std::cout << "\n";

	}
private:
	T* array;
	size_t count = 0;//количество элементов в массиве
	size_t sizeFile = 0;//количество элементов в файле
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
		if (!isalnum(elem))//если добавляемый символ не цифра или литерал, то заменяем его на _
			elem = '_';
		if (count == 64)//если заполнен на 100%
		{
			std::ofstream file("dump.dat", std::ios::app);
			for (size_t i = 0; i < count; i++)
			{
				file << array[i] << "\n";//выгружаем в файл полностью
				sizeFile++;//наращиваем количество элементов, выгруженных в файл
			}

			file.close();
			count = 0;//заполнеение массива обнуляется
		}
		array[count] = elem;//добавляем элемент
		count++;//наращиваем количество элементов
	}
	char popUpper()
	{
		char cmp = array[0];//запоминаем первый элемент во временную переменную
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//смещаем все элементы влево на 1
		size_t i = 0;
		if (count == 64)//если при извлечении освободилось последнее место 
		{
			char* mas = new char[sizeFile];//создаем массив, куда запишем все элементы
			std::ifstream ifile("dump.dat");//поток для чтения
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//последнее место в массиве занимает первый элемент из файла
				count++;

				while (getline(ifile, line) && i < sizeFile)
				{
					mas[i] = atoi(line.c_str());//все строки файла, кроме первого, записываем в массив
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//поток для записи
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//перезаписываем в файл все элементы массива, в котором хранились все строки, кроме первой(этот элемент добавили в конец массива элементов класса)
			offile.close();
			delete[] mas;//удаляем временный массив
		}
		count--;//фиксируем то, что мы изввлекли один элемент
		return toupper(cmp);
	}
	char popLower()
	{
		char cmp = array[0];//запоминаем первый элемент во временную переменную
		for (size_t i = 1; i < count; i++)
			array[i - 1] = array[i];//смещаем все элементы влево на 1
		size_t i = 0;
		if (count == 64)//если при извлечении освободилось последнее место
		{
			char* mas = new char[sizeFile];//создаем массив, куда запишем все элементы
			std::ifstream ifile("dump.dat");//поток для чтения
			if (ifile.is_open())
			{
				std::string line;
				getline(ifile, line);
				array[count - 1] = atoi(line.c_str());//последнее место в массиве занимает первый элемент из файла
				count++;

				while (getline(ifile, line) && i < sizeFile)
				{
					mas[i] = atoi(line.c_str());//все строки файла, кроме первого, записываем в массив
					i++;
				}
			}
			ifile.close();
			std::ofstream offile("dump.dat");//поток для записи
			for (size_t _i = 0; _i < i; _i++)
				offile << mas[_i] << "\n";//перезаписываем в файл все элементы массива, в котором хранились все строки, кроме первой(этот элемент добавили в конец массива элементов класса)
			offile.close();
			delete[] mas;//удаляем временный массив
		}
		count--;//фиксируем то, что мы изввлекли один элемент
		return tolower(cmp);
	}
	void print()
	{
		std::copy(array, array + count, std::ostream_iterator<char>(std::cout, " "));
		std::cout << "\n";
	}
private:
	char* array;
	size_t count = 0;//количество элементов в массиве
	size_t sizeFile = 0;//количество элементов в файле
};
