#include "Animal.h"
#include "WrongCat.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
	const Animal* dog0 = new Dog();
	const Animal* cat0 = new Cat();
	delete dog0;
	delete cat0;
	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;
	{
		const int size = 10;
		Animal **array = new Animal*[size];
		for (int i = 0; i < size / 2; i++) {
			Dog *dog = new Dog();
			array[i] = dog;
			dog->getBrain()->setIdea(0, "Dog idea");
			dog->getBrain()->setIdea(1, "Dog idea 2");
		}
		for (int i = size / 2; i < size; i++) {
			Cat *cat = new Cat();
			array[i] = cat;
			cat->getBrain()->setIdea(0, "Cat idea");
			cat->getBrain()->setIdea(1, "Cat idea 2");
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
		{
			array[i]->makeSound();
			if (array[i]->getType() == "Dog") {
				for (int j = 0; dynamic_cast<Dog*>(array[i])->getBrain()->getIdea(j).empty() == false; j++)
					std::cout << "Dog idea: " << dynamic_cast<Dog*>(array[i])->getBrain()->getIdea(j) << std::endl; 
			}
			else if (array[i]->getType() == "Cat") {
				for (int j = 0; dynamic_cast<Cat*>(array[i])->getBrain()->getIdea(j).empty() == false; j++)
					std::cout << "Cat idea: " << dynamic_cast<Cat*>(array[i])->getBrain()->getIdea(j) << std::endl;
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
			delete array[i];
		delete[] array;
	}
	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;
	{
		// Test deep copy
		Dog* originalDog = new Dog();
		originalDog->getBrain()->setIdea(0, "Original Dog idea");
		Dog* copiedDog = new Dog(*originalDog);
		originalDog->getBrain()->setIdea(0, "New Dog idea");
		std::cout << std::endl;
		std::cout << "Original Dog idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
		delete originalDog;
		delete copiedDog;

		Cat* originalCat = new Cat();
		originalCat->getBrain()->setIdea(0, "Original Cat idea");
		Cat* copiedCat = new Cat(*originalCat);
		originalCat->getBrain()->setIdea(0, "New Cat idea");
		std::cout << std::endl;
		std::cout << "Original Cat idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Cat idea: " << copiedCat->getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
		delete originalCat;
		delete copiedCat;
	}
	return 0;
}
