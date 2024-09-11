#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <string>
# include <deque>



class PmergeMe {
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		std::vector<int> _vec;
		std::deque<int> _deq;

	public:
		PmergeMe();
		~PmergeMe();
		void execute(int argc, char **argv);
		void parseArgs(int argc, char **argv);
		void printVec();
		void printDeq();
};
#endif
