#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#pragma warning(disable : 4996)
// риворучко  сени€, »¬“-2, 4 вариант

/*Ќаписать код дл€ чтени€ произвольного текстового файла и вывода на экран всех слов
размером более 3 букв, встречающихс€ в нем не менее 7 раз, в пор€дке убывани€
частоты встречаемости (приложение ј). ¬ качестве разделителей слов рассматривать
пробел, точку, зап€тую, тире, двоеточие, восклицательный знак, точку с зап€той.
»спользовать контейнер std::map.
*/
int main()
{
	std::map<std::string, int> map;
	std::ifstream file("text.txt", std::ios::app);
	if (file.is_open())
	{
        while (file.peek()!=EOF)//пока поток не закончитс€
        {
            const size_t MAXLEN = 1000;
            char text[MAXLEN];
            file.getline(text, MAXLEN);
            char* substr = std::strtok(text, ".,:!;? ");//разбиваем строку на массив подстрок( в качестве разделител€ знаки пунктуации)
            while (substr != 0)//проходим по массиву подстрок
            {
                std::string word = substr;
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);//приводим к нижнему регистру
                auto it = map.find(word);//ищем словов в контейнере
                if (it == map.end())//если нет, добавл€ем новый элемент контейнера
                    map.insert(std::make_pair(word, 1));
                else
                    map[word]++;//иначе наращиваем значение по ключу(слову)
                substr = std::strtok(NULL, ".,:!;? ");
            }
        }
	}
	file.close();

    std::map <std::string, int> ::iterator it = map.begin();
    std::multimap<int, std::string, std::greater<int>> sorted_map;//создаем контейнер, в котором ключом будет не слово а число, причем отсортированы по убыванию 
    for (int i = 0; it != map.end(); it++, i++)//проходим по всем парам контейнера
        if (it->first.length() > 3 && it->second >= 7)//провер€ем на условие отбора
            sorted_map.insert(std::make_pair(it->second, it->first));//добавл€ем элементы, удовлетвор€ющие условию
    for (auto const& entry : sorted_map)
    {
        std::cout << entry.second << " " << entry.first << std::endl;
    }
    system("pause");
	return 0;
}