#include "ScavTrap.h"

int main() {
	{
		ScavTrap n1;
		ScavTrap n2("Goncalo");
		ScavTrap n3("ScavTrap");
		ScavTrap n4(n2);

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
		n2.attack("Claptrap3");
		n3.takeDamage(n2.get_attack_damage());
		n3.beRepaired(5);
		std::cout << std::endl;

		n4.get_hp();
		n4.get_ep();
		n4.get_attack_damage();
		n4.get_name();
		std::cout << std::endl;

		n1.guardGate();
		n2.guardGate();
		n3.guardGate();
		n4.guardGate();
	}
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	{
		ScavTrap test("test");

		test.attack("enemy");
		test.takeDamage(10);
		test.get_hp();
		test.beRepaired(5);
		test.guardGate();
	}
	return 0;
}
