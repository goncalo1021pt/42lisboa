#ifndef ICharacter_HPP
# define ICharacter_HPP

# include <iostream>

typedef std::string t_string;

class ICharacter {
	private:
		t_string _name;
	public:
		ICharacter();
		~ICharacter();
		ICharacter(const ICharacter &other);
		ICharacter &operator=(const ICharacter &other);
		t_string const &getName() const;
};
#endif
