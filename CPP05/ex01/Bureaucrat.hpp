#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
	private:
			std::string	const 	_name;
			int					_grade;

	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator=(const Bureaucrat &other);
			~Bureaucrat();

			const std::string& getName() const;
			int			getGrade() const;

			void	gradeUp(int up);
			void	gradeDown(int down);

			class GradeTooLowException: public std::exception 
			{
			virtual const char*	what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
			virtual const char*	what() const throw();
			};

			//ex01
			void signForm();
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif