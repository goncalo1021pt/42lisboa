#include "AMateria.h"

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
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "heals " << target.getName() << "'s wounds.. *" << std::endl;
}