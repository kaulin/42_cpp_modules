#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "Creating animal array:" << std::endl;
	{
		const Animal* zoo[10];
		for (int i = 0; i < 10; i++) {
			if (i % 2) zoo[i] = new Dog();
			else zoo[i] = new Cat();
		}
		
		std::cout << "\nTesting animal array:"  << std::endl;
		for (const Animal* animal : zoo) { 
			std::cout << "Animal type " << animal->getType() << std::endl;
			animal->makeSound();
		}

		std::cout << "\nDestroying animal array:" << std::endl;
		for (const Animal* animal : zoo) delete animal;
	}

	std::cout << "\nTesting brains:"  << std::endl;
	{
		Cat cat1;
		std::cout << "Cat1 idea 0 is " << cat1.getIdea(0) << std::endl;
		std::cout << "Cat1 idea 99 is " << cat1.getIdea(99) << std::endl;
		std::cout << "Cat1 idea 100 is " << cat1.getIdea(100) << std::endl;
		Cat cat2(cat1);
		std::cout << "Cat2 idea 0 is " << cat2.getIdea(0) << std::endl;
		std::cout << "Cat2 idea 99 is " << cat2.getIdea(99) << std::endl;
		Dog dog1;
		std::cout << "Dog1 idea 0 is " << dog1.getIdea(0) << std::endl;
		std::cout << "Dog1 idea 99 is " << dog1.getIdea(99) << std::endl;
		dog1.brainwash();
		std::cout << "Dog1 idea 0 is " << dog1.getIdea(0) << std::endl;
		std::cout << "Dog1 idea 99 is " << dog1.getIdea(99) << std::endl;
		Dog dog2(dog1);
		std::cout << "Dog2 idea 0 is " << dog2.getIdea(0) << std::endl;
		std::cout << "Dog2 idea 99 is " << dog2.getIdea(99) << std::endl;
		Dog dog3;
		std::cout << "Dog3 idea 0 is " << dog3.getIdea(0) << std::endl;
		std::cout << "Dog3 idea 99 is " << dog3.getIdea(99) << std::endl;
		dog2 = dog3;
		std::cout << "Dog1 idea 0 is " << dog1.getIdea(0) << std::endl;
		std::cout << "Dog1 idea 99 is " << dog1.getIdea(99) << std::endl;
		std::cout << "Dog2 idea 0 is " << dog2.getIdea(0) << std::endl;
		std::cout << "Dog2 idea 99 is " << dog2.getIdea(99) << std::endl;
		std::cout << "Dog3 idea 0 is " << dog3.getIdea(0) << std::endl;
		std::cout << "Dog3 idea 99 is " << dog3.getIdea(99) << std::endl;
	}
	
	std::cout << "\nDoing deep copy test:" << std::endl;
	{
		Dog basic;
		std::cout << "Basic dog idea 0 is " << basic.getIdea(0) << std::endl;
		basic.brainwash();
		{
			Dog tmp = basic;
			std::cout << "Temporary dog idea 0 is " << basic.getIdea(0) << std::endl;
		}
		std::cout << "Basic dog idea 0 is " << basic.getIdea(0) << std::endl;
	}
	return 0;
}