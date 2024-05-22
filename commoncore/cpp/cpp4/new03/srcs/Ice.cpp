#include "Ice.h"

Ice::Ice() {
	std::cout << "Default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Destructor called" << std::endl;
}

Ice::Ice(const Ice &other) {
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	(void)other;
	return *this;
}
