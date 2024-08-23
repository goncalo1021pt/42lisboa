#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>

typedef std::string t_string;

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		static void convert(t_string stringLiteral);
};
#endif
