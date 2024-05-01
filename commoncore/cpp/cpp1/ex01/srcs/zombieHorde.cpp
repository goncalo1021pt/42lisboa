#include <Zombie.h>

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];
	for (int ctd = 0; ctd < N; ctd++)
		zombies[ctd].setName(name);
	return zombies;
}
