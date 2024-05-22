#include "Cure.hpp"

Cure::Cure() : AMateria() {
	_type = "cure";
}

Cure::Cure(const Cure &src) : AMateria() {
	*this = src;
}

Cure::~Cure() {}

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