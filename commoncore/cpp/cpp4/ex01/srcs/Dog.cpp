#include "Dog.h"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	delete this->brain;
	this->brain = new Brain(*other.brain);
	this->Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

Brain *Dog::getBrain() const {
	return brain;
}