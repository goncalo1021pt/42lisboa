#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try
	{
		PmergeMe p;
		p.execute(argc, argv);
		std::cout << "----------------" << std::endl;
		print(p.getVec());
		std::cout << "----------------" << std::endl;
		print(p.getDeq());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
