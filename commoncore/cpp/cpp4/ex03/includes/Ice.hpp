#ifndef Ice_HPP
#define Ice_HPP

#include "AMateria.h"

class Ice : public AMateria {
	private:

	public:
		Ice();
		Ice(const Ice& src);
		~Ice();
		Ice &operator=(const Ice& src);
		Ice* clone() const;
};
#endif
