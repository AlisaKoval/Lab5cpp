#pragma once
#include <vector>
#include <iostream>
template <typename T>
class Cache
{
public:
	void put(T elem)
	{
		cache.push_back(elem);
	}
	void operator+=(T elem)
	{
		cache.push_back(elem);
	}
	bool contains(T elem)
	{
		return std::find(cache.begin(), cache.end(), elem) != cache.end();
	}
private:
	std::vector<T> cache;
};

template<>
class Cache<std::string>
{
public:
	bool contains(std::string elem)
	{
		for (auto& i : cache)
		{
			if (elem[0] == i[0])//по совпадению первого символа строки
				return true;
			return false;
		}
	}
	void put(std::string elem) 
	{
		try
		{
			if (cache.size() < 100) 
				cache.push_back(elem);

			else
				throw cache.size();
		}
		catch (const size_t ex)
		{
			std::cout << "Error!" << std::endl;
		}
	}
	void operator+=(std::string elem)
	{
		cache.push_back(elem);
	}
private:
	std::vector<std::string> cache;
};


