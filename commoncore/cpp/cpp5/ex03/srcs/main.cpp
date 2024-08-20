#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try
	{
		// Create an Intern
		Intern someRandomIntern;

		// Create forms using the Intern
		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Alice");

		// Print form details to verify creation
		std::cout << "Shrubbery Form: " << shrubberyForm->getName() << std::endl;
		std::cout << "Robotomy Form: " << robotomyForm->getName() << std::endl;
		std::cout << "Pardon Form: " << pardonForm->getName() << std::endl;

		// Create a Bureaucrat
		Bureaucrat bob("Bob", 1);

		// Sign and execute the forms
		shrubberyForm->beSigned(bob);
		shrubberyForm->execute(bob);

		robotomyForm->beSigned(bob);
		robotomyForm->execute(bob);

		pardonForm->beSigned(bob);
		pardonForm->execute(bob);

		// Clean up
		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return 0;
}
