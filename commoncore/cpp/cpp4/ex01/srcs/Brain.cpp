#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	ideaCount = 0;
}

Brain::Brain(const Brain &src) {
*this = src;
}

Brain::~Brain() {}

Brain& Brain::operator=(const Brain &src) {
	(void)src;
	return *this;
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return "";
	}
	if (ideas[index].empty())
	{
		std::cout << "No idea at this index" << std::endl;
		return "";
	}
	return ideas[index];
}
