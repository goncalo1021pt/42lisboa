#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::copy(src.ideas, src.ideas + 100, ideas);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &src) {
	if (this != &src)
		std::copy(src.ideas, src.ideas + 100, ideas);
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
	if (index < 0 || index >= 100 || ideas[index].empty())
		return "";
	return ideas[index];
}
