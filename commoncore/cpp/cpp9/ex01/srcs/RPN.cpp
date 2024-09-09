#include "RPN.hpp"

RPN::RPN() {
	std::cout << "Default constructor called" << std::endl;
}

RPN::~RPN() {
	std::cout << "Destructor called" << std::endl;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

void RPN::parse(int argc, char **argv) {
	if (argc != 2) {
		throw std::runtime_error("Usage: ./rpn \"expression\"");
	}
	std::cout << "Expression: " << argv[1] << std::endl;
	std::string expression = argv[1];
	if (expression.empty()) {
		throw std::runtime_error("Empty expression");
	}
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
		throw std::runtime_error("Error");
	}
	expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());
	
}