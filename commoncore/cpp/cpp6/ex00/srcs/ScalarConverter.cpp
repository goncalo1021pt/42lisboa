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

bool isInff(t_string &stringLiteral) {
	if (stringLiteral == "+inff" || stringLiteral == "+inff" ||
	stringLiteral == "-inf" || stringLiteral == "-inf" || stringLiteral == "nan" || stringLiteral == "nanf")
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
	std::cout << "int" << std::endl;
	try {
		for (int ctd = 0; stringLiteral[ctd]; ctd++)
			if (!std::isdigit(stringLiteral[ctd]) && stringLiteral[ctd]!= '-' && stringLiteral[ctd]!= '+')
				throw std::exception();
		long representation = std::atol(stringLiteral.c_str());
		if (representation < std::numeric_limits<int>::min() || representation > std::numeric_limits<int>::max())
			throw std::exception();
		std::cout << "char: " ;
		if (representation < 255 && representation > -1 && std::isprint(representation))
			std::cout << "'" << static_cast<char>(representation) << "'" << std::endl;
		else
			std::cout << "non-displayable\n";
		std::cout << "int: " << representation << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(representation) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(representation) << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void floatConversion(t_string &stringLiteral) {
	try
	{
		if (stringLiteral.find('-') != stringLiteral.npos && stringLiteral.length() > 10)
			throw std::exception();
		else if (stringLiteral.find('-') == stringLiteral.npos && stringLiteral.length() > 9)
			throw std::exception();
			
		float floatNumber = std::atof(stringLiteral.c_str());
		if (floatNumber < 255 && floatNumber > -1 && std::isprint(floatNumber))
			std::cout << "char: '" << static_cast<char>(floatNumber) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(floatNumber) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << floatNumber << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatNumber) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	
}

void doubleConversion(t_string &stringLiteral) {
	try {
		if (stringLiteral.find('-') != stringLiteral.npos && stringLiteral.length() > 9)
			throw std::exception();
		else if (stringLiteral.find('-') == stringLiteral.npos && stringLiteral.length() > 8)
			throw std::exception();
		double doubleNumber = std::atof(stringLiteral.c_str());
		if (doubleNumber < 255 && doubleNumber > -1 && std::isprint(doubleNumber))
			std::cout << "char: '" << static_cast<char>(doubleNumber) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(doubleNumber) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(doubleNumber) << "f" << std::endl;
		std::cout << "double: " << doubleNumber << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void infinityConvesion(t_string stringLiteral){
	if (stringLiteral == "+inff" || stringLiteral == "+inf") {
		std::cout << "char: " << "char: Non displayable" << std::endl;
		std::cout << "int: " << "+inf" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (stringLiteral == "-inff" || stringLiteral == "-inf") {
		std::cout << "char: " << "char: Non displayable" << std::endl;
		std::cout << "int: " << "-inf" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
}

void ScalarConverter::convert(t_string stringLiteral) {
	if (isFloat(stringLiteral))
		floatConversion(stringLiteral);
	else if (isDouble(stringLiteral))
		doubleConversion(stringLiteral);
	else if (isChar(stringLiteral))
		charConversion(stringLiteral);
	else if (isInff(stringLiteral))
		infinityConvesion(stringLiteral);
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