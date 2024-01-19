#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib> // for srand
#include <ctime>   // for time


template <typename T> class Array
{
	private:
		std::size_t		_size;
		T*				_ptr;

	public:
		Array();
		Array(unsigned int size);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array();

		std::size_t		size() const;
		T &operator[](int index);

		class InvalidIndexException : public std::exception
		{
				virtual const char *what() const throw()
				{
					return ("Invalid: index is either bigger than size or less than 0");
				}
		};


};
#include "Array.tpp"

#endif