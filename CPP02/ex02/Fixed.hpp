#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>
//# include <iomanip>

class Fixed {

	private:
				int					_fixedPoint;
				static const int	_FRACTIONAL;
	public:
				Fixed();
				Fixed(const Fixed& other);
				Fixed(const int value);
				Fixed(const float value);
				Fixed& operator=(const Fixed& other);
				~Fixed();
				int getRawBits() const;
				void setRawBits(int const raw);
				int toInt() const;
				float toFloat() const;

				//ex02
				//The 6 comparison operators: >, <, >=, <=, == and !=.
				bool operator>(const Fixed& other) const;
				bool operator<(const Fixed& other) const;
				bool operator>=(const Fixed& other) const;
				bool operator<=(const Fixed& other) const;
				bool operator==(const Fixed& other) const;
				bool operator!=(const Fixed& other) const;
				
				//The 4 arithmetic operators: +, -, *, and /.
				Fixed operator+(const Fixed& other) const;
				Fixed operator-(const Fixed& other) const;
				Fixed operator*(const Fixed& other) const;
				Fixed operator/(const Fixed& other) const;

				//The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement)
				Fixed& operator++(void);
				Fixed& operator--(void);
				Fixed operator++(int);
				Fixed operator--(int);

				//A static member function min/max that takes as parameters two references to constant/non-constant fixed-point numbers, and returns a reference to the greatest/smallest one.
				static Fixed& min(Fixed& x, Fixed& y);
				static Fixed& max(Fixed& x, Fixed& y);
				static const Fixed& min(const Fixed& x, const Fixed& y);
				static const Fixed& max(const Fixed& x, const Fixed& y);

};

std::ostream &operator<<(std::ostream &stream, Fixed const &a);

#endif