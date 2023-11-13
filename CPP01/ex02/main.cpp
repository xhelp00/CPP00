#include <string>
#include <iostream>

int main(void) {

	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	//print memory
	std::cout << &var << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;


	//print values
	std::cout << var << std::endl;
	std::cout << *stringPTR << " / " << stringPTR << std::endl;
	std::cout << stringREF << std::endl;




	return 0;
}