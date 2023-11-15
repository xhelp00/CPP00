#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {

	private:
				int					_fixedPoint;
				static const int	_FRACTIONAL;
	public:
				Fixed();
				Fixed(const Fixed& other);
				Fixed& operator=(const Fixed& other);
				~Fixed();
				int getRawBits() const;
				void setRawBits(int const raw);
};

#endif