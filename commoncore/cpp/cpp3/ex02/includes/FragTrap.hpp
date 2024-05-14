#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap &operator=(const FragTrap &src);
		void highFivesGuys(void);
};
#endif
