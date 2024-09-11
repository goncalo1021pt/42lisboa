#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

void PmergeMe::parseArgs(int argc, char **argv) {
	int element;

	for (int i = 0; i < argc; i++) {
		element = std::atoi(argv[i]);
		_vec.push_back(element);
		_deq.push_back(element);
		std::cout << element << std::endl;
	}
}

void PmergeMe::printVec() {
	std::vector<int>::iterator it;

	for (it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void PmergeMe::printDeq() {
	std::deque<int>::iterator it;

	for (it = _deq.begin(); it != _deq.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void PmergeMe::execute(int argc, char **argv) {
	parseArgs(argc, argv);
}