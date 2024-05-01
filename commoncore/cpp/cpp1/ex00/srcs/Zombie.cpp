#include <Zombie.hpp>

Zombie::Zombie(t_string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " destructor called" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}