#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return *this;
	return *this;
}
static bool isPseudo(std::string const &in)
{
	return (in == "nan" || in == "nanf" || in == "+inf" || in == "-inf" || in == "+inff" || in == "-inff" || in == "inf" || in == "inff");
}

static bool isSpecialChar(std::string const &in)
{
	return (in.length() == 1 &&	(in[0] == '+' || in[0] == '-' || in[0] == '.' || in[0] == 'f'));
}
static bool hasInvalidSign(std::string const &in)
{
	return (in.find_first_of(SIGN) != in.find_last_of(SIGN));
}

static bool isInt(std::string const &in)
{
	return (in.find_first_not_of(DIGIT_SET) == std::string::npos);
}

static bool isDouble(std::string const &in)
{
	return (in.find_first_not_of(DOUBLE_SET) == std::string::npos);
}

static bool isInvalidDouble(std::string const &in)
{
	return (in.find_first_of(".") != in.find_last_of(".")
		|| isdigit(in[in.find_first_of(".") + 1]) == false
		|| in.find_first_of(".") == 0);
}
static bool isFloat(std::string const &in)
{
	return (in.find_first_not_of(FLOAT_SET) == std::string::npos);
}

static bool isInvalidFloat(std::string const &in)
{
	return (in.find_first_of("f") != in.find_last_of("f")
		|| in.find_first_of(".") != in.find_last_of(".")
		|| in.find_first_of("f") - in.find_first_of(".") == 1
		|| isdigit(in[in.find_first_of(".") + 1]) == false
		|| in.find_first_of(".") == 0);
}

static bool isChar(std::string const &in)
{
	return (in.length() == 1 && isprint(in[0]));
}

int ScalarConverter::parseInput(std::string const &input)
{
	if (isPseudo(input))
		return (PSEUDO);
	else if (isSpecialChar(input))
		return (CHAR);
	else if (hasInvalidSign(input))
		return (ERROR);
	else if (isInt(input))
		return (INT);
	else if (isDouble(input))
	{
		if (isInvalidDouble(input))
			return (ERROR);
		return (DOUBLE);
	}
	else if (isFloat(input))
	{
		if (isInvalidFloat(input))
			return (ERROR);
		return (FLOAT);
	}
	else if (isChar(input))
		return (CHAR);
	else
		return (ERROR);	
}

void ScalarConverter::fromChar(int type, std::string const &input)
{
	char	c = static_cast<unsigned char>(input[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	ScalarConverter::print(type, input, c, i, f, d);
}

void ScalarConverter::fromInt(int type, std::string const &input)
{
	int		i = std::atoi(input.c_str());
	char	c = static_cast<unsigned char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
	ScalarConverter::print(type, input, c, i, f, d);
}

void ScalarConverter::fromFloat(int type, std::string const &input)
{
	float	f = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<float>(f);
	ScalarConverter::print(type, input, c, i, f, d);
}

void ScalarConverter::fromDouble(int type, std::string const &input)
{
	double	d = std::atof(input.c_str());
	char	c = static_cast<unsigned char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	ScalarConverter::print(type, input, c, i, f, d);
}

void ScalarConverter::convert(std::string const &input)
{
	int type = ScalarConverter::parseInput(input);

	switch (type)
	{
		case PSEUDO:
			ScalarConverter::fromDouble(type, input);
			break;
		case ERROR:
			std::cout << "Error: Impossible to print or input not convertable" << std::endl;
			break;
		case CHAR:
			ScalarConverter::fromChar(type, input);
			break;
		case INT:
			ScalarConverter::fromInt(type, input);
			break;
		case FLOAT:
			ScalarConverter::fromFloat(type, input);
			break;
		case DOUBLE:
			ScalarConverter::fromDouble(type, input);
			break;
	}
}

static void printChar(int type, int i, char c)
{
	if (type != PSEUDO && (i >= 0 && i <= UCHAR_MAX))
	{
		if (std::isprint(i))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: non-printable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

static void printInt(int type, std::string const &in, int i)
{
	double check = std::atof(in.c_str());
	
	if (type != PSEUDO && (check >= INT_MIN && check <= INT_MAX))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

static void printNanInf(std::string const &in, std::string const &type)
{
	if (in == "nan" || in == "nanf")
	{
		std::cout << type << ": nan";
		if (type == "float")
			std::cout << "f";
		std::cout << std::endl;
	}
	else if (in == "+inf" || in == "+inff")
	{
		std::cout << type << ": +inf";
		if (type == "float")
			std::cout << "f";
		std::cout << std::endl;
	}
	else if (in == "-inf" || in == "-inff")
	{
		std::cout << type << ": -inf";
		if (type == "float")
			std::cout << "f";
		std::cout << std::endl;
	}
	else if (in == "inf" || in == "inff")
	{
		std::cout << type << ": inf";
		if (type == "float")
			std::cout << "f";
		std::cout << std::endl;
	}
}

static void printFloat(int type, std::string const &input, float f)
{
	if (type != PSEUDO)
	{
		double check = std::atof(input.c_str());

		if (type == INT && (check < INT_MIN || check > INT_MAX))
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else
		printNanInf(input, "float");
}

static void printDouble(int type, std::string const &input, double d)
{
	if (type != PSEUDO)
	{
		double check = std::atof(input.c_str());

		if (type == INT && (check < INT_MIN || check > INT_MAX))
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
		printNanInf(input, "double");
}

void ScalarConverter::print(int type, std::string const &input, char c, int i, float f, double d)
{
	printChar(type, i, c);
	printInt(type, input, i);
	printFloat(type, input, f);
	printDouble(type, input, d);
}