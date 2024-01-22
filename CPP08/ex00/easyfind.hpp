#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class NotFound : public std::exception //has to be defined before easyfind template or include .tpp file at the bottom of this file
{
	virtual const char *what() const throw()
	{
	return ("not found");
	}
};

template <typename T>
void	easyfind(T const container, int n)
{
	if(std::find(container.begin(), container.end(), n) == container.end())
		throw NotFound();
	else
		std::cout << "found" << std::endl;

}



#endif