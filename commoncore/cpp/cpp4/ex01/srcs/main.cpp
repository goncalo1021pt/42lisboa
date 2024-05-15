#include "Animal.h"
#include "WrongCat.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
	const Animal* dog0 = new Dog();
	const Animal* cat0 = new Cat();
	delete dog0;//should not create a leak
	delete cat0;

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
		for (int i = 0; i < size; i++)
		{
			if (array[i]->getType() == "Dog") {
				for (int j = 0; dynamic_cast<Dog*>(array[i])->getBrain()->getIdea(j).empty() != false; j++)
					std::cout << "Dog idea: " << dynamic_cast<Dog*>(array[i])->getBrain()->getIdea(j) << std::endl; 
			}
			else if (array[i]->getType() == "Cat") {
				for (int j = 0; dynamic_cast<Cat*>(array[i])->getBrain()->getIdea(j).empty() != false; j++)
					std::cout << "Cat idea: " << dynamic_cast<Cat*>(array[i])->getBrain()->getIdea(j) << std::endl;
			}
		}
		for (int i = 0; i < size; i++)
			delete array[i];
		delete[] array;
	}
	return 0;
}
