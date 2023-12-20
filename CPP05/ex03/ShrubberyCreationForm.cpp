/*
Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, 
and writes ASCII trees inside it.
*/

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("def")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void) other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string		ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& who) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	else if (who.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
	{
		FILE* pipe = popen("tree", "r"); // Replace "tree" with the full path if necessary
		if (!pipe)
		{
			std::cerr << "Could not open pipe" << std::endl;
			return ;
		}

		// Open the file where you want to save the output
		std::ofstream outFile((_target + "_shrubbery").c_str());
		if (!outFile.is_open()) {
			std::cerr << "Could not open file for writing" << std::endl;
			return ;
		}

		// Read the output of the tree command and write it to the file
		char buffer[256];
		while (fgets(buffer, 256, pipe) != NULL)
		{
			outFile << buffer;
		}

		// Close the pipe and the output file
		pclose(pipe);
		outFile.close();
		std::cout << "Bureaucrat " << who.getName() << " executes " << this->getName() << std::endl;
	}
}