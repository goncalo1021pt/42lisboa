#include <HumanA.h>

HumanA::HumanA(t_string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
	cout << this->name << " attacks with his " << this->weapon.getType() << endl;
}