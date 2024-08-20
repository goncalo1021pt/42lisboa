#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string Intern::formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

AForm* (*Intern::formConstructors[3])(const std::string &target) = {
    &ShrubberyCreationForm::create,
    &RobotomyRequestForm::create,
    &PresidentialPardonForm::create
};

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std :: cout << "Intern creates " << name << std :: endl;
			return formConstructors[i](target);
		}
	}
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}