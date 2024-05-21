#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "Default constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource() {
	std::cout << "Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other) {
	*this = other;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other) {
	(void)other;
	return *this;
}
