#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	parseArgs(argc, argv);
	std::cout << "Before  ";
	print(_vec);
	sortVec();
	sortDeq();
	std::cout << "After   ";
	print(_vec);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vec : " << _timevec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deq : " << _timedeq << " us" << std::endl;
}


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

	if (argc < 2) {
		throw std::runtime_error("Error");
	}
	for (int i = 1; i < argc; i++) {
		element = std::atoi(argv[i]);
		if (element < 0) {
			throw std::runtime_error("Error");
		}
		_vec.push_back(element);
		_deq.push_back(element);
	}
}

void PmergeMe::mergePairsVec(std::vector<int> &vec, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[m + 1 + j];

    int ctd = 0, ctd2 = 0, k = l;
    while (ctd < n1 && ctd2 < n2) {
        if (L[ctd] <= R[ctd2]) {
            vec[k] = L[ctd];
            ctd++;
        } else {
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

void PmergeMe::mergePairsDeq(std::deque<int> &deq, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = deq[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = deq[m + 1 + j];

    int ctd = 0, ctd2 = 0, k = l;
    while (ctd < n1 && ctd2 < n2) {
        if (L[ctd] <= R[ctd2]) {
            deq[k] = L[ctd];
            ctd++;
        } else {
            deq[k] = R[ctd2];
            ctd2++;
        }
        k++;
    }

    while (ctd < n1) {
        deq[k] = L[ctd];
        ctd++;
        k++;
    }

    while (ctd2 < n2) {
        deq[k] = R[ctd2];
        ctd2++;
        k++;
    }
}

void PmergeMe::insertionSortVec(std::vector<int> &vec, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= l && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeq(std::deque<int> &deq, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = deq[i];
        int j = i - 1;
        while (j >= l && deq[j] > key) {
            deq[j + 1] = deq[j];
            j--;
        }
        deq[j + 1] = key;
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}

void PmergeMe::fordJohnsonSortVec(std::vector<int> &vec, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        fordJohnsonSortVec(vec, l, m);
        fordJohnsonSortVec(vec, m + 1, r);
        mergePairsVec(vec, l, m, r);

        std::vector<int> jacobsthal = generateJacobsthalSequence(r - l + 1);
        for (size_t i = 2; i < jacobsthal.size(); i++) {
            int index = l + jacobsthal[i];
            if (index <= r) {
                int key = vec[index];
                int j = index - 1;
                while (j >= l && vec[j] > key) {
                    vec[j + 1] = vec[j];
                    j--;
                }
                vec[j + 1] = key;
            }
        }
    }
}

void PmergeMe::fordJohnsonSortDeq(std::deque<int> &deq, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        fordJohnsonSortDeq(deq, l, m);
        fordJohnsonSortDeq(deq, m + 1, r);
        mergePairsDeq(deq, l, m, r);

        std::vector<int> jacobsthal = generateJacobsthalSequence(r - l + 1);
        for (size_t i = 2; i < jacobsthal.size(); i++) {
            int index = l + jacobsthal[i];
            if (index <= r) {
                int key = deq[index];
                int j = index - 1;
                while (j >= l && deq[j] > key) {
                    deq[j + 1] = deq[j];
                    j--;
                }
                deq[j + 1] = key;
            }
        }
    }
}

void PmergeMe::sortVec() {
    std::clock_t start = std::clock();
    fordJohnsonSortVec(_vec, 0, _vec.size() - 1);
    std::clock_t end = std::clock();
    _timevec = (end - start) * 1000000 / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeq() {
    std::clock_t start = std::clock();
    fordJohnsonSortDeq(_deq, 0, _deq.size() - 1);
    std::clock_t end = std::clock();
    _timedeq = (end - start) * 1000000 / CLOCKS_PER_SEC; 
}

std::vector<int> PmergeMe::getVec() const {
	return _vec;
}

std::deque<int> PmergeMe::getDeq() const {
	return _deq;
}