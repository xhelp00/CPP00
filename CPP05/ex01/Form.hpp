#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>

class Form
{
	private:
				std::string const		_name;
				bool					_isSigned;
				int						_gradeToSign;
				int						_gradeToExe;
				
	public:
			Form();
			Form(const std::string& name, int gradeToSign, int gradeToExe);
			Form(const Form& other);
			Form& operator=(const Form &other);
			~Form();

			void beSigned(Bureaucrat bureaucrat);
			

			class GradeTooLowException: public std::exception 
			{
			virtual const char*	what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
			virtual const char*	what() const throw();
			};

};


#endif