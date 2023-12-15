#include "Form.hpp"

Form::Form():
	_name(""), _gradeToSign(0), _gradeToExe(0)
{
	this->_isSigned = false;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExe): 
	_name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	if (gradeToSign > MIN_GRADE || gradeToExe > MIN_GRADE)
		throw Form::GradeTooLowException();
	else if (gradeToSign < MAX_GRADE || gradeToExe < MAX_GRADE)
		throw Form::GradeTooHighException();
	
	this->_isSigned = false;
}

Form::Form(const Form& other):
	_name(other._name),
	_isSigned(false),
	_gradeToSign(other._gradeToSign), 
	_gradeToExe(other._gradeToExe)
{}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{}

const std::string&	Form::getName() const
{
	return this->_name;
}
bool				Form::getSigned() const
{
	return this->_isSigned;
}
int					Form::getGradeSign() const
{
	return this->_gradeToSign;
}
int					Form::getGradeExec() const
{
	return this->_gradeToExe;
}

void 				Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_isSigned)
		throw AlreadySignedException();
	if (this->_gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* 		Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char* 		Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

std::ostream&	operator<<(std::ostream &o, const Form& form)
{
	o	<< "Form: "				<< form.getName()		<< std::endl
		<< "Status: "			<< form.getSigned()		<< std::endl
		<< "Grade to sign: "	<< form.getGradeSign()	<< std::endl
		<< "Grade to execute: "	<< form.getGradeExec() 	<< std::endl
		<< std::endl;
	return o;
}