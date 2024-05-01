#include <Zombie.h>

int main() {
	Zombie *zombies = zombieHorde(5, "Zombie");
	Zombie *zombies2;
	for (int ctd = 0; ctd < 5; ctd++)
		zombies[ctd].announce();
	zombies2 = zombieHorde(3, "Zombie2");
	for (int ctd = 0; ctd < 3; ctd++)
		zombies2[ctd].announce();
	delete[] zombies;
	delete[] zombies2;
}
