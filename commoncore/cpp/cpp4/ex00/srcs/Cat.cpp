#include "Cat.h"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal() {
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	this->Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}
