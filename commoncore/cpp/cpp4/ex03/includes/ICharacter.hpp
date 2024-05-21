#ifndef ICharacter_HPP
# define ICharacter_HPP

# include <iostream>
# include "AMateria.hpp"

typedef std::string t_string;

class ICharacter {
	private:
		t_string _name;
		AMateria *_inventory[4];
	public:
		ICharacter();
		ICharacter(t_string name);
		virtual ~ICharacter();
		ICharacter(const ICharacter &other);
		ICharacter &operator=(const ICharacter &other);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
#endif
