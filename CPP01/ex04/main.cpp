#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error. \nWrong number of arguments. \nUse: ./Sed filename string1 string2" << std::endl;
		return 1;
	}
	
	// Open file for reading
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error. \nOpening file for reading failed." << std::endl;
		return 1;
	}
	// Read content into a string
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content = buffer.str();
	// Manually perform replacements
	std::string target = av[2];
	std::string replacement = av[3];
	std::string newContent;
	size_t pos = 0;
	while (true) {
		size_t found = content.find(target, pos);
		if (found != std::string::npos)
		{
			newContent.append(content, pos, found - pos); // Append part of the original string
			newContent.append(replacement);               // Append the replacement string
			pos = found + target.length();               // Move past the replaced part
		}
		else
		{
			newContent.append(content, pos, std::string::npos); // Append the rest of the original string
			break;
		}
	}
	// Open file for writing
	std::ofstream outFile(av[1]);
	if (!outFile.is_open())
	{
		std::cerr << "Error. \nOpening file for writing failed." << std::endl;
		return 1;
	}
	outFile << newContent;
	outFile.close();

	return 0;

}

