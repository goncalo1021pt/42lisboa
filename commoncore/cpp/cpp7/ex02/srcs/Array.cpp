#include "Array.h"

Array::Array() {
	std::cout << "Default constructor called" << std::endl;
}

Array::~Array() {
	std::cout << "Destructor called" << std::endl;
}

Array::Array(const Array &other) {
	*this = other;
}

Array &Array::operator=(const Array &other) {
	(void)other;
	return *this;
}
