#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern
{
		private:

		public:
				Intern();
				Intern(const Intern& other);
				Intern& operator=(const Intern& other);
				~Intern();

				AForm* makeForm(std::string name, std::string target);

				class UnknownException: public std::exception 
				{
				virtual const char*	what() const throw();
				};
};

#endif