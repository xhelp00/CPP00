#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
				std::string const		_name;
				bool					_isSigned;
				int const				_gradeToSign;
				int const				_gradeToExe;
				
	public:
			Form();
			Form(const std::string& name, int gradeToSign, int gradeToExe);
			Form(const Form& other);
			Form& operator=(const Form &other);
			~Form();


			const std::string&	getName() const;
			bool				getSigned() const;
			int					getGradeSign() const;
			int					getGradeExec() const;

			void beSigned(const Bureaucrat& bureaucrat);
			

			class GradeTooLowException: public std::exception 
			{
			virtual const char*	what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
			virtual const char*	what() const throw();
			};

			class AlreadySignedException: public std::exception
			{
			virtual const char*	what() const throw();
			};

};

std::ostream&	operator<<(std::ostream& o, const Form& form);


#endif