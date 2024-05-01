#include <Zombie.h>

int main() {
	Zombie* zombie;
	zombie = newZombie("Zombie1");
	zombie->announce();
	randomChump("Zombie2");
	randomChump("Zombie3");
	zombie->announce();
	delete zombie;
	return 0;
}
