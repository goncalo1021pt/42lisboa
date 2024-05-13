#include "ClapTrap.h"

int main() {
	ClapTrap claptrap;
	ClapTrap claptrap2("Goncalo");
	ClapTrap claptrap3("Claptrap3");
	ClapTrap claptrap4(claptrap2);

	claptrap.attack("Goncalo");
	claptrap2.takeDamage(claptrap.get_attack_damage());
	claptrap2.get_hp();
	claptrap2.beRepaired(5);
	std::cout << std::endl;

	claptrap3.attack("Goncalo");
	claptrap3.takeDamage(claptrap2.get_attack_damage());
	claptrap3.get_hp();
	std::cout << std::endl;

	claptrap2.set_attack_damage(10);
	claptrap2.attack("Claptrap3");
	claptrap3.takeDamage(claptrap2.get_attack_damage());
	claptrap3.beRepaired(5);
	std::cout << std::endl;

	claptrap4.get_hp();
	claptrap4.get_ep();
	claptrap4.get_attack_damage();
	claptrap4.get_name();

	return 0;
}
