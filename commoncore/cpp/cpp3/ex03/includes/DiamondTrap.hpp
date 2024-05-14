#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include <ScavTrap.h>
# include <FragTrap.h>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap& src);
		void attack(std::string const & target);
		void whoAmI();
};
#endif
