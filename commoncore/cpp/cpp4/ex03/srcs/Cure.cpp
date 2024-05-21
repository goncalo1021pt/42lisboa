#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure &src) {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &src) {
	_type = src._type;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}