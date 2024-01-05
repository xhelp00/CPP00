#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

#define SIGN		"+-"
#define DIGIT_SET	"+-0123456789"
#define DOUBLE_SET	"+-0123456789."
#define FLOAT_SET	"+-0123456789.f"

#define PSEUDO	1
#define ERROR	2
#define CHAR	3
#define INT		4
#define FLOAT	5
#define DOUBLE	6

class ScalarConverter 
{
	private:

		static int parseInput(const std::string& input);
		static void fromChar(int type, const std::string& input);
		static void fromInt(int type, const std::string& input);
		static void fromFloat(int type, const std::string& input);
		static void fromDouble(int type, const std::string& input);
		static void print(int type, const std::string& input, char c, int i, float f, double d);
		
	public:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);

		static void convert(const std::string& input);
		
};

#endif