#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")  {}

ShrubberyCreationForm::ShrubberyCreationForm(t_string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137) {
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	this->checkExecution(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileNotOpenException();
	file << "Ascii trees" << std::endl;
}

const char * ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "Exception: File not open";
}
