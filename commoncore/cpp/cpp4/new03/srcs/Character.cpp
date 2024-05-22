#include "Character.h"

Character::Character() {
	std::cout << "Default constructor called" << std::endl;
}

Character::~Character() {
	std::cout << "Destructor called" << std::endl;
}

Character::Character(const Character &other) {
	*this = other;
}

Character &Character::operator=(const Character &other) {
	(void)other;
	return *this;
}
