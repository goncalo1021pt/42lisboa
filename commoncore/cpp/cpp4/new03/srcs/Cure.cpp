#include "Cure.h"

Cure::Cure() {
	std::cout << "Default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Destructor called" << std::endl;
}

Cure::Cure(const Cure &other) {
	*this = other;
}

Cure &Cure::operator=(const Cure &other) {
	(void)other;
	return *this;
}
