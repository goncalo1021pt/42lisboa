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

	for (int i = 1; i < argc; i++) {
		element = std::atoi(argv[i]);
		_vec.push_back(element);
		_deq.push_back(element);
		// std::cout << element << std::endl;
	}
}

void PmergeMe::merge(std::vector<int> &vec, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int ctd = 0; ctd < n1; ctd++)
	{
        L[ctd] = vec[l + ctd];
	}

    for (int ctd2 = 0; ctd2 < n2; ctd2++)
	{
        R[ctd2] = vec[m + 1 + ctd2];
	}

	int ctd = 0;
	int ctd2 = 0;
    int k = l;
	while (ctd < n1 && ctd2 < n2) {
        if (L[ctd] <= R[ctd2]) {
            vec[k] = L[ctd];
            ctd++;
        }
        else {
            vec[k] = R[ctd2];
            ctd2++;
        }
        k++;
    }

	 while (ctd < n1) {
        vec[k] = L[ctd];
        ctd++;
        k++;
    }

    while (ctd2 < n2) {
        vec[k] = R[ctd2];
        ctd2++;
        k++;
    }
}

void PmergeMe::mergeSort(std::vector<int> &vec, int l, int r)
{
	int m;

	if (l < r) {
		m = l + (r - l) / 2;
		mergeSort(vec, l, m);
		mergeSort(vec, m + 1, r);
		merge(vec, l, m, r);
	}
}

void PmergeMe::sortVec() {
	std::cout << "Vector:" << std::endl;
	// std::sort(_vec.begin(), _vec.end());
	// merge-insertion sort
	mergeSort(_vec, 0, _vec.size() - 1);

}

void PmergeMe::sortDeq() {
	// std::sort(_deq.begin(), _deq.end());
}

void PmergeMe::execute(int argc, char **argv) {
	
	parseArgs(argc, argv);
	sortVec();
	sortDeq();
}

std::vector<int> PmergeMe::getVec() const {
	return _vec;
}

std::deque<int> PmergeMe::getDeq() const {
	return _deq;
}