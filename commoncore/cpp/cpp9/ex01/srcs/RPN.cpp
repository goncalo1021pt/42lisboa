#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

bool RPN::isOperator(const std::string &token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

double RPN::calculate(double a, double b, const std::string &op)
{
	if (op == "+")
		return a + b;
    else if (op == "-")
		return a - b;
    else if (op == "*")	
		return a * b;
   else {
        if (b == 0) 
			throw std::runtime_error("Division by zero");
        return a / b;
    }
}

void RPN::checkExpression(const std::string &expression) {
	if (expression.empty()) {
		throw std::runtime_error("Error");
	}
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
		throw std::runtime_error("Error");
	}
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == ' ') 
			i++;
		if (isOperator(std::string(1, expression[i]))) {
			if (!(expression[i + 1] == ' ' || expression[i + 1] == '\0')) {
				throw std::runtime_error("Error");
			}
		} else if (expression[i] >= '0' && expression[i] <= '9') {
			if (!(expression[i + 1] == ' ' || expression[i + 1] == '\0')) {
				throw std::runtime_error("Error");
			}
		}
		
	}
}

void RPN::parse(int argc, char **argv) {
	if (argc != 2) {
		throw std::runtime_error("Usage: ./rpn \"expression\"");
	}
	std::string expression = argv[1];
	checkExpression(expression);
	
	std::istringstream iss(expression);
	std::string token;
	double a, b, result;
	while (iss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error");
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			result = calculate(b, a, token);
			_stack.push(result);
		} else {
			double number;
            std::istringstream numStream(token);
            if (!(numStream >> number)) {
                throw std::runtime_error("Error");
            }
            _stack.push(number);
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	std::cout << _stack.top() << std::endl;
}