#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include <stack>
# include <list>
# include <algorithm>

class RPN {
	private:
		std::stack<double, std::list<double> > _stack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		bool isOperator(const std::string &token);
		double calculate(double a, double b, const std::string &op);
		void checkExpression(const std::string &expression);

	public:
		RPN();
		~RPN();
		void parse(int argc, char **argv);
};
#endif
