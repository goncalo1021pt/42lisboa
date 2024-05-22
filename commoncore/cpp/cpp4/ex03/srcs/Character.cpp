#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const t_string &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character &src) {
	*this = src;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

Character& Character::operator=(const Character &src) {
	(void)src;
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
	for (int i = 0; i < 4; i++) {
		if (!_materia[i]) {
			_materia[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || _materia[idx] == NULL)
		return ;
	_materia[idx] = NULL;
}


