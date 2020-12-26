#include"DataManager.h"
//Криворучко Ксения, ИВТ-2, 4 вариант

/*Написать шаблонный класс DataManager<T> для специфической работы с набором
однотипных данных(максимальная вместимость равна 64 элементам).В набор можно
добавлять данные(метод push(T elem) для добавления одного элемента и метод
	push(T elems[], size_t n) для добавления группы из n элементов), считывать без
	извлечения(метод T peek()) и извлекать(метод T pop()) по некоторым алгоритмам
	(в соответствии с вариантом, приложение А).Если набор заполнен на 100 % и
	поступает команда добавления нового элемента(ов), то данные полностью
	выгружаются(дописываются) в специальный файл dump.dat, а сам массив очищается
	и новые данные записываются уже в обновленный набор.Если из массива удаляется
	последний элемент, то он заполняется ранее выгруженными в файл данными(если
		файл не пуст).
	Необходимо также реализовать явную специализацию шаблонного класса для
	символьного типа.В ней надо запрограммировать следующее : при добавлении
	символа в набор все знаки пунктуации должны автоматически заменяться на символ
	подчеркивания; добавить методы char popUpper() и char popLower(), которые
	позволяют при извлечении символа из набора привести его к верхнему или нижнему
	регистру, соответственно.
	В функции main() продемонстрировать применение шаблонного класса DataManager
	для типов int, double и char.Элементы контейнера должны выводиться на консоль с
	помощью std::ostream_iterator.*/

/*Вариант 4.
push(): данные пишутся на первое свободное место в наборе;
peek(): возвращает второй элемент в наборе или 0, если элементов в наборе меньше 2;
pop(): извлекает первый элемент.*/
int main()
{
	DataManager<int> manager;
	manager.push(3);//в manager 3
	int arr[50] = { 0 };
	manager.push(arr, 50);//в manager 3 и 50 нулей
	int arr1[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	manager.push(arr1, 13);//в manager 3, 50 нулей и 1-13
	int a = manager.peek();//а=3
	manager.push(111);//3, 50 нулей и 1-13 выгрузилось в файлю. в manager 111
	manager.push(arr,50);//в manager 111 и 50 нулей
	manager.push(arr1, 13);//в manager 111, 50 нудей и 1-13
	int b = manager.pop();//b=111. в manager 50 нулей, 1-13 и 3
	int c = manager.pop();//с=0. в manager 49 нулей, 1-13, 3 и 0
	std::cout << a << "\t" << b << "\t" << c << std::endl;//3	11	0
	manager.print();//49 нулей, 1-13, 3 и 0
	DataManager<double> double_manager;
	double_manager.push(2.1);
	double_manager.push(5.3);
	double_manager.push(1.0);
	double_manager.print();//2.1 5.3 1.0
	double d = double_manager.pop();//d=2.1
	std::cout << d << std::endl;//2.1
	DataManager<char> char_manager;
	char_manager.push('K');
	char_manager.push('c');
	char_manager.push('-');
	char_manager.push('K');
	char_manager.push('c');
	char_manager.push('-');
	char_manager.push('K');
	char_manager.push('c');
	char_manager.push('!');
	char_manager.print();//Kc_Kc_Kc_
	char e = char_manager.popLower();//e=k
	char f = char_manager.popUpper();//f=C
	std::cout << e << "\t" << f << std::endl;//k	C
	return 0;
}