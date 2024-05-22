#ifndef IMateriaSource_HPP
# define IMateriaSource_HPP

# include <iostream>
# include "AMateria.hpp"

typedef std::string t_string;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif
