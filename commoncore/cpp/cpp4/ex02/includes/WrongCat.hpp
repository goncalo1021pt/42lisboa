#ifndef WrongCat_HPP
#define WrongCat_HPP

# include "WrongAnimal.h"

typedef std::string t_string;

class WrongCat : public WrongAnimal {
	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		void makeSound() const;
};

#endif
