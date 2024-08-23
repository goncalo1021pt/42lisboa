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
	if (isprint(stringLiteral[0]))
		std::cout << "char: '" << stringLiteral[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	int intNumber = static_cast<int>(stringLiteral[0]);
	std::cout << "int: " << intNumber << std::endl;
	float floatNumber = static_cast<float>(intNumber);
	std::cout << "float: " << floatNumber << "f" << std::endl;
	double doubleNumber = static_cast<double>(intNumber);
	std::cout << "double: " << doubleNumber << std::endl;
}

void intConversion(t_string &stringLiteral) {
	(void)stringLiteral;
	std::cout << "int" << std::endl;
	// int intNumber = std::stoi(stringLiteral);
	// std::cout << "int: " << intNumber << std::endl;
}

void floatConversion(t_string &stringLiteral) {
	(void)stringLiteral;
	std::cout << "float" << std::endl;
	// try {
	// 	float floatNumber = std::stof(stringLiteral);
	// 	std::cout << "float: " << floatNumber << "f" << std::endl;
	// } catch (std::exception &e) {
	// 	std::cout << "float: impossible" << std::endl;
	// }
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
