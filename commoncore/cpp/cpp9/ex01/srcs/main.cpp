#include "RPN.hpp"

int main(int argc, char **argv) {
	try {
		RPN rpn;
		rpn.parse(argc, argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
	
}
