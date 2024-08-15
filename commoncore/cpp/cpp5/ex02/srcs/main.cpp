#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
try
    {
        std::cout << "-----------------ShrubberyCreationForm-----------------\n\n";
        ShrubberyCreationForm doc1("doc1");
        {
            Bureaucrat bob("Bob", 150);
            bob.signForm(doc1);
            bob.executeForm(doc1);
        }
        std::cout << "\n";
        {
            Bureaucrat bob("Bob", 138);
            bob.executeForm(doc1);
        }
        std::cout << "\n";
        {
            Bureaucrat bob("Bob", 138);
            bob.signForm(doc1); // will be signed in the next scope
            bob.executeForm(doc1);
        }
        std::cout << "\n";
        {
            Bureaucrat bob("Bob", 100);
            bob.executeForm(doc1);
        }
        std::cout << "\n-----------------RobotomyRequestForm-----------------\n\n";
        RobotomyRequestForm doc2("doc2");
        {
            Bureaucrat jim("Jim", 55);
            jim.signForm(doc2);
            jim.executeForm(doc2);
        }
        std::cout << "\n";
        {
            Bureaucrat jim("Jim", 42);
            jim.executeForm(doc2);
        }
        std::cout << "\n-----------------PresidentialPardonFormquestForm-----------------\n\n";
        PresidentialPardonForm doc3("doc3");
        Bureaucrat tim("Tim", 1);
        tim.signForm(doc3);
        tim.executeForm(doc3);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
	return 0;
}
