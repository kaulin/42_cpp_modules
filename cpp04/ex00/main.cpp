#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "Testing working animals:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\nTesting wrong animals:" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	k->makeSound(); //will output the cat sound!
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\nDestroying:" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;
	delete k;
	return 0;
}