#ifndef Character_HPP
# define Character_HPP

# include <iostream>

typedef std::string t_string;

class Character {
	private:

	public:
		Character();
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
};
#endif
