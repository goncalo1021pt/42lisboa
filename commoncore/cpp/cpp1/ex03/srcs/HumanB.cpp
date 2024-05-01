#include <HumanB.h>

HumanB::HumanB(t_string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
void HumanB::attack() {
	Weapon *weapon = this->weapon;
	if (weapon == NULL)
		cout << this->name << " has no weapon" << endl;
	else
		cout << this->name << " attacks with his " << this->weapon->getType() << endl;
}