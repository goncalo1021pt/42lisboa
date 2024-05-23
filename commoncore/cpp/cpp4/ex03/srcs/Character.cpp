#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int ctd = 0; ctd < 4; ctd++)
		_materia[ctd] = NULL;
}

Character::Character(const t_string &name) : _name(name) {
	for (int ctd = 0; ctd < 4; ctd++)
		_materia[ctd] = NULL;
}

Character::Character(const Character &src) {
	for (int ctd = 0; ctd < 4; ctd++) {
		if (src._materia[ctd])
			_materia[ctd] = src._materia[ctd]->clone();
		else
			_materia[ctd] = NULL;
	}
}

Character::~Character() {
	for (int ctd = 0; ctd < 4; ctd++)
		if (_materia[ctd])
			delete _materia[ctd];
}

Character& Character::operator=(const Character &src) {
	if (this == &src)
		return *this;
	for (int ctd = 0; ctd < 4; ctd++) {
		if (_materia[ctd])
			delete _materia[ctd];
		if (src._materia[ctd])
			_materia[ctd] = src._materia[ctd]->clone();
		else
			_materia[ctd] = NULL;
	}
	return *this;
}

t_string const & Character::getName() const {
	return _name;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4 || !_materia[idx])
		return ;
	_materia[idx]->use(target);
}

void Character::equip(AMateria* m) {
	
	for (int ctd = 0; ctd < 4; ctd++) {
		if (!_materia[ctd]) {
			_materia[ctd] = m;
			break;
		}
		if (ctd == 3)
			delete m;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || _materia[idx] == NULL)
		return ;
	_materia[idx] = NULL;
}


