#ifndef Character_HPP
#define Character_HPP

#include "ICharacter.hpp"
#include <iostream>

typedef std::string t_string;

class Character : public ICharacter{
	private:
		t_string _name;
		AMateria *_materia[4];

	public:
		Character();
		Character(const t_string &name);
		Character(const Character &src);
		~Character();
		Character &operator=(const Character &src);
		virtual t_string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};
#endif
