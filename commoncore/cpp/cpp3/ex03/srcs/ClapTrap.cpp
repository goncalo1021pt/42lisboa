#include "ClapTrap.h"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _attack_damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(t_string name) : _name(name), _hp(10), _ep(10), _attack_damage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_damage = other._attack_damage;
	}
	return *this;
}

void ClapTrap::attack(t_string const &target) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	if (_ep < 1)
	{
		std::cout << _name << " is out of energy!" << std::endl;
		return ;
	}
	_ep--;
	std::cout << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	_hp -= amount;
	std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hp < 1)
	{
		std::cout << _name << " is dead!" << std::endl;
		_hp = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	if (_ep < 1)
	{
		std::cout << _name << " is out of energy!" << std::endl;
		return ;
	}
	if (_hp < 10)
	{
		_ep--;
		if (_hp + amount > 10)
		{
			amount = 10 - _hp;
			_hp = 10;
		}
		else
			_hp += amount;
		std::cout << _name << " is repaired for " << amount << " points!" << std::endl;
	}
	else
		std::cout << _name << " is already at full health!" << std::endl;
}

int ClapTrap::get_hp() const {
	if (_hp < 1)
		std::cout << _name << " is dead!" << std::endl;
	else
		std::cout << _name << " has " << _hp << " hit points!" << std::endl;
	return _hp;
}

int ClapTrap::get_ep() const {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return 0;
	}
	if (_ep < 1)
		std::cout << _name << " is out of energy!" << std::endl;
	else
		std::cout << _name << " has " << _ep << " energy points!" << std::endl;
	return _ep;
}

int ClapTrap::get_attack_damage() const {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return 0;
	}
	std::cout << _name << " has " << _attack_damage << " attack damage!" << std::endl;
	return _attack_damage;
}

t_string ClapTrap::get_name() const {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return _name;
	}
	std::cout << "ClapTrap name is " << _name << std::endl;
	return _name;
}

void ClapTrap::set_hp(int hp) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		_hp = 0;
		return ;
	}
	_hp = hp;
	std::cout << _name << " now has " << _hp << " hit points!" << std::endl;
}

void ClapTrap::set_ep(int ep) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		_ep = 0;
		return ;
	}
	_ep = ep;
	std::cout << _name << " now has " << _ep << " energy points!" << std::endl;
}

void ClapTrap::set_attack_damage(int attack_damage) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		_attack_damage = 0;
		return ;
	}
	_attack_damage = attack_damage;
	std::cout << _name << " now has " << _attack_damage << " attack damage!" << std::endl;
}

void ClapTrap::set_name(t_string name) {
	if (_hp < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << _name << " is now named " << name << std::endl;
	_name = name;
}
