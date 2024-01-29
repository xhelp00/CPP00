#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	std::string	line;
	std::ifstream database("data.csv");
	if (!database.is_open())
	{
		std::cerr << "Error: cannot open data.csv file" << std::endl;
			exit(1);
	}
	std::getline(database, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: data.csv file has wrong format" << std::endl;
		exit(1);
	}
	while (std::getline(database, line)) {
		try {
			check_record(line, 'D');
			std::stringstream stream(line);
			std::string date;
			std::string value;
			std::getline(stream, date, ',');
			std::getline(stream, value);
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			_record.insert(std::pair<std::string, double>(date, std::strtod(value.c_str(), NULL)));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: database: " << e.what() << std::endl;
			exit(1);
		}
	}
	database.close();
}

Bitcoin::Bitcoin(Bitcoin const &other)
{
	*this = other;
}

Bitcoin &Bitcoin::operator=(Bitcoin const &other)
{
	if (this != &other)
		this->_record = other._record;
	return *this;
}

Bitcoin::~Bitcoin()
{}

void	Bitcoin::check_date(std::string date)
{
	char	*format;
	strtod(date.c_str(), &format);
	
	if (*format != '\0' && *format != '-')
		throw std::invalid_argument("wrong date format: " + date);

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("wrong date format: " + date);
	
	int year = std::atoi((date.substr(0, 4)).c_str());
	int	month = std::atoi((date.substr(5, 2)).c_str());
	int day = std::atoi((date.substr(8, 2)).c_str());
	
	if (year > 2024 || year < 2009)
		throw std::invalid_argument("year out of range: " + date);
	if (month > 12 || month < 1)
		throw std::invalid_argument("month out of range: " + date);
	if (day > 31 || day < 1)
		throw std::invalid_argument("day out of range: " + date);
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12) && day > 31)
		throw std::invalid_argument("day out of range: " + date);
	if (month == 2 && (day > 28 || (day > 29 && (year == 2012 || year == 2016 || year == 2020 || year == 2024))))
		throw std::invalid_argument("day out of range: " + date);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::invalid_argument("day out of range: " + date);
	
}

void	Bitcoin::check_value(std::string value, char source)
{
	char	*format;
	double	token = strtod(value.c_str(), &format);

	if (*format != '\0')
		throw std::invalid_argument("wrong input value: " + value);
	if (token < 0)
		throw std::invalid_argument("not a positive number");
	if (token > 1000 && source == 'I')
		throw std::invalid_argument("value out of range (MAX 1000)");
}

void	Bitcoin::check_record(std::string record, char source)
{
	std::string	date;
	std::string	value;

	std::stringstream stream(record);
	if (source == 'I')
	{
		stream >> date;
		stream >> value >> value;
	}
	else
	{
		std::getline(stream, date, ',');
		std::getline(stream, value, ',');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
	}
	if (date == "" || value == "")
	{
		if (date == "")
			throw std::invalid_argument("empty date input");
		if (value == "") {
			check_date(date);
			throw std::invalid_argument("empty value input");
		}
	}
	check_date(date);
	check_value(value, source);
}

void	Bitcoin::read_file(std::string file)
{
	std::string line;
	std::ifstream input(file.c_str());
	if (!input.is_open())
	{
		std::cout << "Error: could not open file '" << file << "'" << std::endl;
		exit(1); 
	}
	std::getline(input, line);
	if (line != "date | value")
	{
		std::cout << "Error: file '" << file << "' has wrong format" << std::endl;
		exit(1);
	}
	while (std::getline(input, line))
	{
		try
		{
			check_record(line, 'I');
			std::stringstream stream(line);
			std::string date;
			std::string value;
			stream >> date;
			stream >> value >> value; //rewrites the delimiter

			std::map<std::string, double>::iterator it;
			it = _record.lower_bound(date);
			double rate = it->second;
			if (it != _record.begin()) {
				if (it->first != date)
					--it;
				rate = it->second;
			}
			std::cout << date << " => " << value << " = " << rate * std::strtod(value.c_str(), NULL) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: input file: " << e.what() << std::endl;
		}
	}
	input.close();
}
