#ifndef Cure_HPP
# define Cure_HPP

# include <iostream>

typedef std::string t_string;

class Cure {
	private:

	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
};
#endif
