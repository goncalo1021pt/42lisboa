#ifndef Ice_HPP
#define Ice_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	private:

	public:
		Ice();
		Ice(const Ice& src);
		~Ice();
		Ice &operator=(const Ice& src);

		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);
};
#endif
