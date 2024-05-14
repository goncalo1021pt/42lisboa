#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap& src);
		void attack(std::string const & target);
		void guardGate();
};
#endif
