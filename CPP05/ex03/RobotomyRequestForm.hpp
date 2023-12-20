#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{

	private:
				const std::string		_target;

	public:
				RobotomyRequestForm();
				RobotomyRequestForm(std::string target);
				RobotomyRequestForm(const RobotomyRequestForm& other);
				RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
				~RobotomyRequestForm();

				void					execute(const Bureaucrat& who) const;

				std::string				getTarget() const;

};

#endif