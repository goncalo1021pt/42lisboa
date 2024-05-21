#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:

	public:
		Cure();
		Cure(const Cure& src);
		~Cure();
		Cure &operator=(const Cure& src);

		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);
};
#endif
