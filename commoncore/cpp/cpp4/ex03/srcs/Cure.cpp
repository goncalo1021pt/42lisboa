#include "Cure.hpp"

Cure::Cure() {
	_type = "cure";
}

Cure::Cure(const Cure &src) {
	*this = src;
}

Cure::~Cure() {
	
}

Cure& Cure::operator=(const Cure &src) {
	(void)src;
	return *this;
}
