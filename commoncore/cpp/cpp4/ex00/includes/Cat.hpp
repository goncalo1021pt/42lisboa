#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.h"

typedef std::string t_string;

class Cat : public Animal {
	private:

	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound() const;
};
#endif
