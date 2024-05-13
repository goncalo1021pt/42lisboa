#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) { *this = src; }

ScavTrap::~ScavTrap() {}

ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
    (void)src;
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    std::cout << "ScavTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_attack_damage() << " points of damage!" << std::endl;
}