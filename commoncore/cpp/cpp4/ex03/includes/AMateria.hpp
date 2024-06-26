#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include "ICharacter.hpp"

typedef std::string t_string;
class ICharacter;

class AMateria {
	protected:
		t_string _type;
		
	public:
		AMateria();
		AMateria(t_string const &type);
		virtual ~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		t_string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};
#endif
