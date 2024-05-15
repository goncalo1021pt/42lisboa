#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Default";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

t_string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Default WrongAnimal sound" << std::endl;
}
