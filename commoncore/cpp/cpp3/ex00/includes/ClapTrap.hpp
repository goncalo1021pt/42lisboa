#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

typedef std::string t_string;

class ClapTrap {
	private:
		t_string _name;
		int _hp;
		int _ep;
		int _attack_damage;
	public:
		ClapTrap();
		ClapTrap(t_string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void attack(t_string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int get_hp() const;
		int get_ep() const;
		int get_attack_damage() const;
		t_string get_name() const;
		void set_hp(int hp);
		void set_ep(int ep);
		void set_attack_damage(int attack_damage);
		void set_name(t_string name);
};
#endif
