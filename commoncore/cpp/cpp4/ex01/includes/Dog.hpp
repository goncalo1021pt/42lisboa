#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.h"

typedef std::string t_string;

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void makeSound() const;
		Brain *getBrain() const;
};
#endif
