#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include <Weapon.hpp>

using std::cout;
using std::endl;
typedef std::string t_string;

class HumanA
{
	private:
		t_string name;
		Weapon &weapon;
	public:
		HumanA(t_string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif