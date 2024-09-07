#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>
#include <cstdlib>
#include <ctime>   

class Span {
	private:
		unsigned int _n;
		std::vector<int> v;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void fillVector();
};
#endif
