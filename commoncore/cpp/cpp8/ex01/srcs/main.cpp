#include "Span.hpp"

int main() {
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "---------------" << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span sp1 = Span(100);
	sp1.fillVector();
	std::cout << "ShortestSpan: " << sp1.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << sp1.longestSpan() << std::endl;
	std::cout << "---------------" << std::endl << std::endl;

	Span sp2 = Span(10000);
	sp2.fillVector();
	std::cout << "ShortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << sp2.longestSpan() << std::endl;
	std::cout << "---------------" << std::endl << std::endl;

	Span sp3 = Span();
	try {
		sp3.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "ShortestSpan: " << sp3.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
