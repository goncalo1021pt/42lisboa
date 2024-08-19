#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
       // Create bureaucrats
        Bureaucrat highLevel("High Level", 1);
        Bureaucrat midLevel("Mid Level", 70);
        Bureaucrat lowLevel("Low Level", 150);

        // Create forms
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Employee");
        PresidentialPardonForm pardonForm("Criminal");

        // highLevel.signForm(shrubberyForm);
        // highLevel.executeForm(shrubberyForm);
        // highLevel.signForm(robotomyForm);
        // highLevel.executeForm(robotomyForm);
        // highLevel.signForm(pardonForm);
        // highLevel.executeForm(pardonForm);

        // Test mid level bureaucrat
        std::cout << "\nTesting mid level bureaucrat:" << std::endl;
        midLevel.signForm(shrubberyForm);
        midLevel.executeForm(shrubberyForm);
        midLevel.signForm(robotomyForm);
        midLevel.executeForm(robotomyForm);
        midLevel.signForm(pardonForm);
        midLevel.executeForm(pardonForm);

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
	return 0;
}
