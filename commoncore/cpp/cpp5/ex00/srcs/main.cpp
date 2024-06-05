#include "Bureaucrat.h"

int main() {
	try {
		Bureaucrat b1("b1", 1);

		std::cout << b1 << std::endl;
		b1.decrementGrade(25);
		std::cout << b1 << std::endl;
		b1.incrementGrade(10);
		std::cout << b1 << std::endl;

		Bureaucrat b2("b2", 1);

		std::cout << b2 << std::endl;
		b2.incrementGrade(150);
		std::cout << b2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
