#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{

}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::gradeUp(int up)
{
	std::cout << "Attempted to raise a grade by " << up << std::endl;
	if (_grade - up < MAX_GRADE)
		throw GradeTooHighException();
	_grade -= up;
}

void	Bureaucrat::gradeDown(int down)
{
	std::cout << "Attempted to lower a grade by " << down << std::endl;
	if (_grade + down > MIN_GRADE)
		throw GradeTooLowException();
	_grade += down;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high!";
}

void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout	<< _name << " cannot sign " << form.getName() << " because "
					<< e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat)
{
	o	<< bureaucrat.getName() << ", bureaucrat of grade "
		<< bureaucrat.getGrade() << std::endl
		<< std::endl;
	return o;
}


