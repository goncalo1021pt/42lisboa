#include "ScalarConverter.hpp"

bool isFloat(t_string &stringLiteral) {
	if (stringLiteral.find('.') == stringLiteral.npos)
		return false;
	char lastChar = stringLiteral[stringLiteral.length() - 1];
    if (lastChar != 'f' && lastChar != 'F') {
        return false;
    }
	t_string floatString = stringLiteral.substr(0, stringLiteral.length() - 1);
	char *end;
	strtod(floatString.c_str(), &end);
	if (*end != '\0')
		return false;
	return true;
}

bool isDouble(const t_string &stringLiteral) {
    char *end;
    strtod(stringLiteral.c_str(), &end);

	if (stringLiteral.find('.') == stringLiteral.npos)
		return false;
    return (*end == '\0' && end != stringLiteral.c_str());
}

bool isChar(t_string &stringLiteral) {
	if (stringLiteral.length() != 1)
	{
		return false;
	}
	if (!isdigit(stringLiteral[0]))
		return true;
	return false;
}

void charConversion(t_string &stringLiteral) {
	char c = static_cast<char>(stringLiteral[0]);
	int i = static_cast<int>(c);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i <<  std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void intConversion(t_string &stringLiteral) {
	(void)stringLiteral;
	std::cout << "int" << std::endl;
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void floatConversion(t_string &stringLiteral) {
	std::cout << "float" << std::endl;
	try {
		float f = std::atof(stringLiteral.c_str());
		if (stringLiteral.length() > 9)
			throw std::exception();
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << 'f' << std::endl;
		std::cout << "double: " << d << std::endl;	

	} catch (std::exception &e) {
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << "+inff\n";
		std::cout << "double: " << "+inff" << std::endl;
	}
}

void doubleConversion(t_string &stringLiteral) {
	(void)stringLiteral;
	std::cout << "double" << std::endl;
	// double doubleNumber = std::stod(stringLiteral);
	// std::cout << "double: " << doubleNumber << std::endl;
}

void ScalarConverter::convert(t_string stringLiteral) {
	if (isFloat(stringLiteral))
		floatConversion(stringLiteral);
	else if (isDouble(stringLiteral))
		doubleConversion(stringLiteral);
	else if (isChar(stringLiteral))
		charConversion(stringLiteral);
	else
		intConversion(stringLiteral);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
