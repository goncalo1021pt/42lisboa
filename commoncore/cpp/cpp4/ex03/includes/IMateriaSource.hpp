#ifndef IMateriaSource_HPP
# define IMateriaSource_HPP

# include <iostream>

typedef std::string t_string;

class IMateriaSource {
	private:

	public:
		IMateriaSource();
		~IMateriaSource();
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
};
#endif
