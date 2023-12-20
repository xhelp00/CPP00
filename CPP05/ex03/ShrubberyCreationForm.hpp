#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{

	private:
				const std::string		_target;

	public:
				ShrubberyCreationForm();
				ShrubberyCreationForm(std::string target);
				ShrubberyCreationForm(const ShrubberyCreationForm& other);
				ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
				~ShrubberyCreationForm();

				void					execute(const Bureaucrat& who) const;

				std::string				getTarget() const;

};

#endif