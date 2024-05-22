#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

typedef std::string t_string;

class AMateria {
	protected:

	public:
		AMateria();
		AMateria(const t_string &type);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		const t_string &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};
#endif
