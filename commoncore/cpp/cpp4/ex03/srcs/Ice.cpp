#include "Ice.hpp"

Ice::Ice() : AMateria(){
	_type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(){
	*this = src;
}

Ice::~Ice() {}

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
