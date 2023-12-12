#include "Form.hpp"















std::ostream&	operator<<(std::ostream &o, const Form& form)
{
	o	<< "Form: "				<< form.getName()		<< std::endl
		<< "Status: "			<< form.getSigned()		<< std::endl
		<< "Grade to sign: "	<< form.getGradeSign()	<< std::endl
		<< "Grade to execute: "	<< form.getGradeExec() 	<< std::endl;
		
	return o;
}