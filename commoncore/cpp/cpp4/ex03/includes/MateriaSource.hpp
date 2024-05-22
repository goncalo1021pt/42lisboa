#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materia[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource& src);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};
#endif
