#include "Ice.hpp"

Ice::Ice() {
	std::cout << "Ice default constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &src) {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &src) {
	_type = src._type;
	return *this;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}
