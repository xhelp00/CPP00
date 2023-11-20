#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>


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
};

std::ostream &operator<<(std::ostream &stream, Fixed const &a);

#endif