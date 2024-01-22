#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
			MutantStack(){};
			MutantStack(const MutantStack &other)
			{
				*this = other;
				}
			MutantStack& operator=(const MutantStack &other)
			{
				(void)other;
				return *this;
			}
			~MutantStack(){};
	
	
	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
};


#endif