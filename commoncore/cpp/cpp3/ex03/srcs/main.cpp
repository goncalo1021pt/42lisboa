#include "DiamondTrap.h"

int main() {
	{
		DiamondTrap n1;
		DiamondTrap n2("Goncalo");
		DiamondTrap n3("DiamondTrap");
		DiamondTrap n4(n2);

		n1.attack("Goncalo");
		n2.takeDamage(n1.get_attack_damage());
		n2.get_hp();
		n2.beRepaired(5);
		std::cout << std::endl;

		n3.attack("Goncalo");
		n3.takeDamage(n2.get_attack_damage());
		n3.get_hp();
		std::cout << std::endl;

		n2.set_attack_damage(10);
		n2.attack("DiamondTrap");
		n3.takeDamage(n2.get_attack_damage());
		n3.beRepaired(5);
		std::cout << std::endl;

		n4.get_hp();
		n4.get_ep();
		n4.get_attack_damage();
		n4.get_name();
		std::cout << std::endl;

		n1.highFivesGuys();
		n2.highFivesGuys();
		n3.highFivesGuys();
		n4.highFivesGuys();
	}
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	{
		DiamondTrap test("test");

		test.get_hp();
		test.get_ep();
		test.get_attack_damage();
		test.whoAmI();
	}
	return 0;
}
