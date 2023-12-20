/*
Required grades: sign 72, exec 45
Makes some drilling noises. 
Then, informs that <target> has been robotomized
successfully 50% of the time. 
Otherwise, informs that the robotomy failed.
*/

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 75, 45), _target("def")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 75, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void) other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string		RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& who) const
{
	int	success = rand() % 2; 

	if (this->getSigned() == false)
		throw AForm::NotSignedException();

	else if (who.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();

	else if (success)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << " failed." << std::endl;
}