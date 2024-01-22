#include "Span.hpp"
#include <climits>

Span::Span()
{
	this->_maxSize = 0;
	this->_vec.reserve(0);
}

Span::Span(unsigned int size)
{
	this->_maxSize = size;
	//std::vector<int> _vec;
	this->_vec.reserve(size);
}

Span::Span(Span const &other)
{
this->_vec = other._vec; 
this->_maxSize = other._maxSize;
}
Span::~Span()
{}

Span	&Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_maxSize = other._maxSize;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_vec.size() == this->_maxSize)
		throw FullVector();
	this->_vec.push_back(n);
}

void	Span::addRange(int from, int to)
{
	if (from >= to)
		throw IncorrectRange();
	if ((static_cast<int>(getMaxSize()) - static_cast<int>(_vec.size())) < (to - from))
		throw FullVector();

	std::vector<int> range;
	range.reserve(to - from);
	for (int i = from; i <= to; i++)
	{
		range .push_back(i);
	}
	this->_vec.insert(_vec.end(), range.begin(), range.end());
}

int	Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw NotEnoughElements();
	
	sort(_vec.begin(), _vec.end());
	
	int	diff = INT_MAX;
	for (std::vector<int>::iterator num = _vec.begin() + 1; num != _vec.end(); num++)
	{
		std::vector<int>::iterator prev = num - 1;
		if (*num - *prev < diff || num == _vec.begin() + 1)
			diff = abs(*num - *prev);
	}
	return (diff);
}

int	Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw NotEnoughElements();
	
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	int diff = abs(max - min);
	return (diff);
}

int	Span::getMember(int i) const
{
	if (i < 0 || i > (int)this->_vec.size() - 1) //valid index only for existing numbers in vector
		throw OutOfRange();
	return (this->_vec[i]);
}

unsigned int	Span::getMaxSize() const
{
	return (this->_maxSize);
}


