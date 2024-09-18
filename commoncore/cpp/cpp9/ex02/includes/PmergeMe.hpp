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
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		std::vector<int> _vec;
		std::deque<int> _deq;
		long _timevec;
		long _timedeq;
		void parseArgs(int argc, char **argv);
		void sortVec();
		void sortDeq();
		void mergePairsVec(std::vector<int> &vec, int l, int m, int r);
		void mergePairsDeq(std::deque<int> &deq, int l, int m, int r);
		void insertionSortVec(std::vector<int> &vec, int l, int r);
		void insertionSortDeq(std::deque<int> &deq, int l, int r);
		void fordJohnsonSortVec(std::vector<int> &vec, int l, int r);
		void fordJohnsonSortDeq(std::deque<int> &deq, int l, int r);
		std::vector<int> generateJacobsthalSequence(int n);
		PmergeMe();

	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		std::vector<int> getVec() const;
		std::deque<int> getDeq() const;
};
#endif
