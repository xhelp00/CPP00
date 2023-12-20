#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{

	private:
				const std::string		_target;

	public:
				PresidentialPardonForm();
				PresidentialPardonForm(std::string target);
				PresidentialPardonForm(const PresidentialPardonForm& other);
				PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
				~PresidentialPardonForm();

				void					execute(const Bureaucrat& who) const;

				std::string				getTarget() const;

};

#endif