#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

class Bitcoin
{
	private:
		std::map<std::string, double> 			_record;

		void	check_date(std::string date);
		void	check_value(std::string value, char source);
		void	check_record(std::string record, char source);
	
	public:
		Bitcoin();
		Bitcoin(Bitcoin const &other);
		Bitcoin &operator=(Bitcoin const &other);
		~Bitcoin();
		
		void	read_file(std::string file);
};




#endif