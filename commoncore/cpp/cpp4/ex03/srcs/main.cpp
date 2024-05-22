#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		// Test learning more than 4 materias
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		// Test creating a materia of unknown type
		AMateria* unknown = src->createMateria("unknown");
		if (unknown == NULL)
			std::cout << "Unknown materia type correctly handled" << std::endl;

		ICharacter* me = new Character("me");
		AMateria* tmp;

		// Test equipping more than 4 materias
		for (int ctd = 0; ctd < 5; ctd++) {
			if (ctd < 2)
				tmp = src->createMateria("cure");
			else
				tmp = src->createMateria("ice");
			me->equip(tmp);
		}

		ICharacter* bob = new Character("bob");
		for (int ctd = 0; ctd < 4; ctd++)
        	me->use(ctd, *bob);

		// Test using a materia in an invalid slot
		me->use(4, *bob);

		delete bob;
		delete me;
		delete src;
	}
}

