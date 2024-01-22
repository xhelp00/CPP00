#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


class Span
{
	public:
		Span();
		Span(unsigned int size);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void	addNumber(int n);
		void	addRange(int from, int to);

		int		shortestSpan();
		int		longestSpan();

		int				getMember(int i) const;
		unsigned int 	getMaxSize() const;

	private:
		std::vector<int>	_vec;
		unsigned int		_maxSize;

		class FullVector : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("vector is full");
			}
		};

		class NotEnoughElements : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("not enough elements in vector (0 or 1)");
			}
		};

		class OutOfRange : public std::exception
		{
				virtual const char *what() const throw()
				{
					return ("index is out of range");
				}
		};

		class IncorrectRange : public std::exception
		{
				virtual const char *what() const throw()
				{
					return ("bad range");
				}
		};
};


#endif