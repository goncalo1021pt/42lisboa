#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::Ice(const Ice &src) {
*this = src;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &src) {
	(void)src;
	return *this;
}

Ice* Ice::clone() const {
	return new Ice(*this);
}
