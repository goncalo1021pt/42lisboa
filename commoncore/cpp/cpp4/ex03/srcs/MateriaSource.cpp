#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int ctd = 0; ctd < 4; ctd++)
		_materia[ctd] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int ctd = 0; ctd < 4; ctd++)
		delete _materia[ctd];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src) {
	if (this == &src)
		return *this;
	for (int ctd = 0; ctd < 4; ctd++)
		_materia[ctd] = src._materia[ctd]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int ctd = 0; ctd < 4; ctd++) {
		if (_materia[ctd] == NULL) {
			_materia[ctd] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int ctd = 0; ctd < 4; ctd++) {
		if (_materia[ctd] != NULL && _materia[ctd]->getType() == type)
			return _materia[ctd]->clone();
	}
	return NULL;
}
