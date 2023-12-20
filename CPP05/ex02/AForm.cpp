#include "AForm.hpp"

AForm::AForm():
	_name(""), _gradeToSign(0), _gradeToExe(0)
{
	this->_isSigned = false;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExe): 
	_name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	if (gradeToSign > MIN_GRADE || gradeToExe > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < MAX_GRADE || gradeToExe < MAX_GRADE)
		throw AForm::GradeTooHighException();
	
	this->_isSigned = false;
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_isSigned(false),
	_gradeToSign(other._gradeToSign), 
	_gradeToExe(other._gradeToExe)
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{}

const std::string&	AForm::getName() const
{
	return this->_name;
}
bool				AForm::getSigned() const
{
	return this->_isSigned;
}
int					AForm::getGradeSign() const
{
	return this->_gradeToSign;
}
int					AForm::getGradeExec() const
{
	return this->_gradeToExe;
}

void 				AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_isSigned)
		throw AlreadySignedException();
	if (this->_gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* 		AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char* 		AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char*			AForm::AlreadySignedException::what() const throw()
{
	return "AForm is already signed!";
}

const char*			AForm::NotSignedException::what(void) const throw()
{
	return ("Form not signed!");
}

std::ostream&	operator<<(std::ostream &o, const AForm& AForm)
{
	o	<< "AForm: "				<< AForm.getName()		<< std::endl
		<< "Status: "			<< AForm.getSigned()		<< std::endl
		<< "Grade to sign: "	<< AForm.getGradeSign()	<< std::endl
		<< "Grade to execute: "	<< AForm.getGradeExec() 	<< std::endl
		<< std::endl;
	return o;
}