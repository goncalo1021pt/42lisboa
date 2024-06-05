#include "Bureaucrat.h"

int main() {
	try {
        Bureaucrat b("goncalo", 2);
        std::cout << b << std::endl;

        Form f("Form1", 1, 1);
        std::cout << f << std::endl;

        b.signForm(f);
        std::cout << f << std::endl;
        std::cout << std::endl << "---------------------" << std::endl << std::endl;

        Bureaucrat b2("Joao", 5);
        std::cout << b2 << std::endl;

        b2.signForm(f);
        std::cout << f << std::endl;

        std::cout << std::endl << "---------------------" << std::endl << std::endl;
        Bureaucrat b3("Maria", 1);
        std::cout << b3 << std::endl;

        Form f2("Form2", 2, 2);
        std::cout << f2 << std::endl;

        b3.signForm(f2);
        std::cout << f2 << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
