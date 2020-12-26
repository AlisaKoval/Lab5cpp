#include"DataManager.h"
//���������� ������, ���-2, 4 �������

/*�������� ��������� ����� DataManager<T> ��� ������������� ������ � �������
���������� ������(������������ ����������� ����� 64 ���������).� ����� �����
��������� ������(����� push(T elem) ��� ���������� ������ �������� � �����
	push(T elems[], size_t n) ��� ���������� ������ �� n ���������), ��������� ���
	����������(����� T peek()) � ���������(����� T pop()) �� ��������� ����������
	(� ������������ � ���������, ���������� �).���� ����� �������� �� 100 % �
	��������� ������� ���������� ������ ��������(��), �� ������ ���������
	�����������(������������) � ����������� ���� dump.dat, � ��� ������ ���������
	� ����� ������ ������������ ��� � ����������� �����.���� �� ������� ���������
	��������� �������, �� �� ����������� ����� ������������ � ���� �������(����
		���� �� ����).
	���������� ����� ����������� ����� ������������� ���������� ������ ���
	����������� ����.� ��� ���� ����������������� ��������� : ��� ����������
	������� � ����� ��� ����� ���������� ������ ������������� ���������� �� ������
	�������������; �������� ������ char popUpper() � char popLower(), �������
	��������� ��� ���������� ������� �� ������ �������� ��� � �������� ��� �������
	��������, ��������������.
	� ������� main() ������������������ ���������� ���������� ������ DataManager
	��� ����� int, double � char.�������� ���������� ������ ���������� �� ������� �
	������� std::ostream_iterator.*/

/*������� 4.
push(): ������ ������� �� ������ ��������� ����� � ������;
peek(): ���������� ������ ������� � ������ ��� 0, ���� ��������� � ������ ������ 2;
pop(): ��������� ������ �������.*/
int main()
{
	DataManager<int> manager;
	manager.push(3);//� manager 3
	int arr[50] = { 0 };
	manager.push(arr, 50);//� manager 3 � 50 �����
	int arr1[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	manager.push(arr1, 13);//� manager 3, 50 ����� � 1-13
	int a = manager.peek();//�=3
	manager.push(111);//3, 50 ����� � 1-13 ����������� � �����. � manager 111
	manager.push(arr,50);//� manager 111 � 50 �����
	manager.push(arr1, 13);//� manager 111, 50 ����� � 1-13
	int b = manager.pop();//b=111. � manager 50 �����, 1-13 � 3
	int c = manager.pop();//�=0. � manager 49 �����, 1-13, 3 � 0
	std::cout << a << "\t" << b << "\t" << c << std::endl;//3	11	0
	manager.print();//49 �����, 1-13, 3 � 0
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