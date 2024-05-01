#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
typedef std::string t_string;
using std::string;
using std::cout;

class Weapon
{
private:
	t_string type;
public:
	Weapon(t_string type);
	~Weapon();
	const t_string &getType() const;
	void setType(t_string type);
};


#endif