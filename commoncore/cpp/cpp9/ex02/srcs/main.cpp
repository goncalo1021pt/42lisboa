#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try
	{
		PmergeMe p;
		p.execute(argc, argv);
		std::cout << "----------------" << std::endl;
		p.printVec();
		std::cout << "----------------" << std::endl;
		p.printDeq();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
