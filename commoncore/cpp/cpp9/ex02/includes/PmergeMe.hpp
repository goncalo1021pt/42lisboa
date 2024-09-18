#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <string>
# include <deque>
# include <ctime>
# include <sstream>


template <typename T>
void print(T container) {
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << std::endl;
	}
}

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		std::vector<int> _vec;
		std::deque<int> _deq;
		void parseArgs(int argc, char **argv);
		void sortVec();
		void sortDeq();
		void mergeSort(std::vector<int> &vec, int l, int r);
		void merge(std::vector<int> &vec, int l, int m, int r);
		void insertionSort(std::vector<int> &vec, int l, int r);
	public:
		PmergeMe();
		~PmergeMe();
		void execute(int argc, char **argv);
		std::vector<int> getVec() const;
		std::deque<int> getDeq() const;
};
#endif
