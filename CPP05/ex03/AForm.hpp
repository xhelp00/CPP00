#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	//not private 
	protected:
				std::string const		_name;
				bool					_isSigned;
				int const				_gradeToSign;
				int const				_gradeToExe;
				
	public:
			AForm();
			AForm(const std::string& name, int gradeToSign, int gradeToExe);
			AForm(const AForm& other);
			AForm &operator=(const AForm &other);
			~AForm();


			const std::string&	getName() const;
			bool				getSigned() const;
			int					getGradeSign() const;
			int					getGradeExec() const;

			// signing is always the same so I made it non virtual
			void	beSigned(const Bureaucrat& bureaucrat);
			// pure virtual method as every form has different execution therefore it will be overriden
			virtual void	execute(const Bureaucrat& executor) const = 0;
			

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

			class NotSignedException: public std::exception
			{
			virtual char const	*what(void) const throw();
			};

};

std::ostream&	operator<<(std::ostream& o, const AForm& form);


#endif