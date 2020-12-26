#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#pragma warning(disable : 4996)
//���������� ������, ���-2, 4 �������

/*�������� ��� ��� ������ ������������� ���������� ����� � ������ �� ����� ���� ����
�������� ����� 3 ����, ������������� � ��� �� ����� 7 ���, � ������� ��������
������� ������������� (���������� �). � �������� ������������ ���� �������������
������, �����, �������, ����, ���������, ��������������� ����, ����� � �������.
������������ ��������� std::map.
*/
int main()
{
	std::map<std::string, int> map;
	std::ifstream file("text.txt", std::ios::app);
	if (file.is_open())
	{
        while (file.peek()!=EOF)//���� ����� �� ����������
        {
            const size_t MAXLEN = 1000;
            char text[MAXLEN];
            file.getline(text, MAXLEN);
            char* substr = std::strtok(text, ".,:!;? ");//��������� ������ �� ������ ��������( � �������� ����������� ����� ����������)
            while (substr != 0)//�������� �� ������� ��������
            {
                std::string word = substr;
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);//�������� � ������� ��������
                auto it = map.find(word);//���� ������ � ����������
                if (it == map.end())//���� ���, ��������� ����� ������� ����������
                    map.insert(std::make_pair(word, 1));
                else
                    map[word]++;//����� ���������� �������� �� �����(�����)
                substr = std::strtok(NULL, ".,:!;? ");
            }
        }
	}
	file.close();

    std::map <std::string, int> ::iterator it = map.begin();
    std::multimap<int, std::string, std::greater<int>> sorted_map;//������� ���������, � ������� ������ ����� �� ����� � �����, ������ ������������� �� �������� 
    for (int i = 0; it != map.end(); it++, i++)//�������� �� ���� ����� ����������
        if (it->first.length() > 3 && it->second >= 7)//��������� �� ������� ������
            sorted_map.insert(std::make_pair(it->second, it->first));//��������� ��������, ��������������� �������
    for (auto const& entry : sorted_map)
    {
        std::cout << entry.second << " " << entry.first << std::endl;
    }
    system("pause");
	return 0;
}