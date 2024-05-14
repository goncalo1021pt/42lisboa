#include "FragTrap.h"

int main() {
	{
		FragTrap n1;
		FragTrap n2("Goncalo");
		FragTrap n3("FragTrap");
		FragTrap n4(n2);

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
		n2.attack("FragTrap");
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
		FragTrap test("test");

		test.attack("enemy");
		test.takeDamage(10);
		test.get_hp();
		test.beRepaired(5);
		test.highFivesGuys();
	}
	return 0;
}
