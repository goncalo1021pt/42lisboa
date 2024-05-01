#include <Zombie.hpp>

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << _name << " destructor called" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(t_string name) {
	_name = name;
}
