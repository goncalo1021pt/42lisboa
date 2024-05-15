#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

typedef std::string t_string;

class WrongAnimal {
	protected:
		t_string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		t_string getType() const;
		virtual void makeSound() const;
};
#endif
