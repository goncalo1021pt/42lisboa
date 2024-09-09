#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include <stack>
# include <algorithm>

class RPN {
	private:
		std::stack<int> _stack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

	public:
		RPN();
		~RPN();
		void parse(int argc, char **argv);
};
#endif
