#include "iter.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5};

	::iter(arr, 5, ::print<int>);
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;
	
	char arr2[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arr2, 5, ::print<char>);
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;

	std::string arr3[] = {"Hello", "World", "!"};
	::iter(arr3, 3, ::print<std::string>);
	return 0;
}
