#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int N) : _n(N) {}

Span::~Span() {}

Span::Span(const Span &other) : _n(other._n), v(other.v) {
	(void)other;
}

Span &Span::operator=(const Span &other) {
	(void)other;
	return *this;
}

void Span::addNumber(int num) {
	if (v.size() < _n)
		v.insert(std::lower_bound(v.begin(), v.end(), num), num);
	else
		throw std::runtime_error("Span is full");
}

int Span::shortestSpan() {
	int min;
	int span;

	if (v.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span");

	min = std::numeric_limits<int>::max();
	for (size_t ctd = 1; ctd < v.size(); ctd++) {
		span = v[ctd] - v[ctd - 1];
		if (span < min)
			min = span;
	}
	return min;
}

int Span::longestSpan() {
	if (v.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span");
	return v.back() - v.front();
}

void Span::fillVector() {
	std::srand(std::time(0));
	while (v.size() < _n)
	{
		addNumber(std::rand());
	}
}