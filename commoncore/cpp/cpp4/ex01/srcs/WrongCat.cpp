#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal() {
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return *this;
	this->WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}