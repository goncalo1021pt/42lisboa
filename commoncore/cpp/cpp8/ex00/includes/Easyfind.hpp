#ifndef Easyfind_HPP
# define Easyfind_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

template <typename T>
int easyfind(T container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return *it;
}

#endif