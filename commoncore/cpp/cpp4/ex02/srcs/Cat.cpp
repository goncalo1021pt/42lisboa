#include "Cat.h"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	delete this->brain;
	this->brain = new Brain(*other.brain);
	this->Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

Brain *Cat::getBrain() const {
	return brain;
}
