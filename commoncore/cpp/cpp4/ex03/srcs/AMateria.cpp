#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Default constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	(void)other;
	return *this;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}
