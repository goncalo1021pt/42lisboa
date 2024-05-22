#ifndef Ice_HPP
# define Ice_HPP

# include <iostream>

typedef std::string t_string;

class Ice {
	private:

	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
};
#endif
