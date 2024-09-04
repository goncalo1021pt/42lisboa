#ifndef Array_HPP
# define Array_HPP

# include <iostream>

typedef std::string t_string;

class Array {
	private:

	public:
		Array();
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
};
#endif
