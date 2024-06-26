#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::~AMateria() {
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

std::string const &AMateria::getType() const {
	return _type;
}
