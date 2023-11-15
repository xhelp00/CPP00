#include "Fixed.hpp"

const int		Fixed::_FRACTIONAL = 8;

Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called." << std::endl;
}

//copying classes can be shallow or deep, as there are no dynamically allocated variables in this scope, shallow copy is good enough
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	//this->_fixedPoint = other.getRawBits();
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_fixedPoint = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member method called." << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	this->_fixedPoint = value * 256;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->_fixedPoint = roundf(value * 256);
}

int Fixed::toInt() const
{
	return (int)this->_fixedPoint / 256;
}

float Fixed::toFloat() const
{
	return (float)this->_fixedPoint / 256;
}

//<< operator overload
std::ostream &operator<<(std::ostream &stream, Fixed const &other)
{
	stream << other.toFloat();
	return stream;
}