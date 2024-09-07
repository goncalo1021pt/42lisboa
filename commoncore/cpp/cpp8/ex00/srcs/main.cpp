#include "Easyfind.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int arr2[] = {10, 20, 30, 40, 50};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(int));

	try {
		std::cout << "Found: " << easyfind(vec, 3) << std::endl;
		std::cout << "Found: " << easyfind(lst, 20) << std::endl; 
		std::cout << "Found: " << easyfind(vec, 6) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
