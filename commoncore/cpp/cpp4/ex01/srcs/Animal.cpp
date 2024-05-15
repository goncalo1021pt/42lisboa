#include "Animal.h"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Default";
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

t_string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Default animal sound" << std::endl;
}
