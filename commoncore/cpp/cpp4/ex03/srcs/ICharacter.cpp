#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(t_string name) : _name(name) {
	std::cout << "ICharacter Name constructor called" << std::endl;
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other) {
	std::cout << "ICharacter copy constructor called" << std::endl;
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = other._inventory[i]->clone();
	}
}
