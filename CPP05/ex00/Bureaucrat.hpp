#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:

	public:
			Bureaucrat();
			Bureaucrat(const Bureaucrat &other);
			Bureaucrat& operator=(const Bureaucrat &other);
			~Bureaucrat();
};


#endif