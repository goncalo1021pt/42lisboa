#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
    _hp = 100;
    _ep = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _name = name; 
    _hp = 100;
    _ep = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    *this = src; 
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    _name = src._name;
    _hp = src._hp;
    _ep = src._ep;
    _attack_damage = src._attack_damage;
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}