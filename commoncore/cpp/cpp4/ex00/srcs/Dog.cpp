#include "Dog.h"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal() {
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	this->Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}
