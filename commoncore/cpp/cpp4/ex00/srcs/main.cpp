#include "Animal.h"
#include "WrongCat.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;
	{
		Dog a1;
		Cat a2;
		Animal a3;

		std::cout << a1.getType() << std::endl;
		a1.makeSound();
		std::cout << a2.getType() << std::endl;
		a2.makeSound();
		std::cout << a3.getType() << std::endl;
		a3.makeSound();
	}
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;
	{
		WrongCat a1;
		Animal a2;

		std::cout << a1.getType() << std::endl;
		a1.makeSound();
		std::cout << a2.getType() << std::endl;
		a2.makeSound();
	}
	return 0;
}
