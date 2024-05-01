#include <Zombie.hpp>

Zombie* newZombie(t_string name) {
	Zombie* zombie = new Zombie(name);
	return zombie;
}
