#include "ICharacter.h"

ICharacter::ICharacter() {
	std::cout << "Default constructor called" << std::endl;
}

ICharacter::~ICharacter() {
	std::cout << "Destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other) {
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
	(void)other;
	return *this;
}
