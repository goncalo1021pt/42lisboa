#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include <Weapon.hpp>

using std::cout;
using std::endl;
typedef std::string t_string;

class HumanB
{
	private:
		t_string name;
		Weapon *weapon;
	public:
		HumanB(t_string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif