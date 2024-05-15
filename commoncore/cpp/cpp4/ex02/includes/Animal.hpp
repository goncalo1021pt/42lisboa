#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include "Brain.h"

typedef std::string t_string;

class Animal {
	protected:
		t_string type;
		Animal();
	public:
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		t_string getType() const;
		virtual void makeSound() const = 0;
};
#endif
