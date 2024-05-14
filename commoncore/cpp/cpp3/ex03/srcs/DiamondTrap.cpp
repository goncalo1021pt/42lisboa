#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("default") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_hp = FragTrap::_hp;
	this->_ep = 50;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = 50;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) { 
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ep = src._ep;
		this->_attack_damage = src._attack_damage;
	}
	return *this;
}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap Name: " << this->_name << std::endl;
	std::cout << "ClapTrap Name: " << ClapTrap::_name << std::endl;
}


/* The "diamond problem" (also sometimes referred to as the "deadly diamond of death") is an ambiguity that arises when a class inherits from two or more classes that have a common base class. This can lead to a lot of confusion and errors in a program due to the way that inheritance works in C++.
Here's a simple example:
    A
   / \
  B   C
   \ /
    D
In this diagram, D inherits from both B and C, which both inherit from A. This forms a diamond shape, hence the name "diamond problem".
The problem arises when a method is invoked that is defined in A and overridden in B and C, and there is no overriding method in D. When that method is invoked on an object of type D, the compiler doesn't know whether to use B's implementation or C's.
In C++, this problem is resolved using "virtual inheritance". By declaring that B and C inherit virtually from A, you're telling the compiler that there should only be one A object in any object of class D.
In your case, DiamondTrap is D, ScavTrap and FragTrap are B and C, and ClapTrap is A. You've correctly used virtual inheritance (ScavTrap and FragTrap both virtually inherit from ClapTrap) to avoid the diamond problem. */