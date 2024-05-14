#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hp = 100;
	_ep = 100;
	_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hp = 100;
	_ep = 100;
	_attack_damage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src) {
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_attack_damage = src._attack_damage;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
