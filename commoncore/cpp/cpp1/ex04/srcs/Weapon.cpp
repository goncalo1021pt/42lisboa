#include <Weapon.h>

Weapon::Weapon(t_string type) : type(type) {}

Weapon::~Weapon() {}

t_string const &Weapon::getType() const {
	return type;
}

void Weapon::setType(const t_string type) {
	this->type = type;
}