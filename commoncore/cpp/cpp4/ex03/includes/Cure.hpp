#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.h"

class Cure : public AMateria {
	private:

	public:
		Cure();
		Cure(const Cure& src);
		~Cure();
		Cure &operator=(const Cure& src);
		Cure* clone() const;
};
#endif
