#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "Testing working animals:" << std::endl;
	const Animal* animalAnimal = new Animal();
	const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();
	std::cout << animalDog->getType() << " " << std::endl;
	std::cout << animalCat->getType() << " " << std::endl;
	animalCat->makeSound();
	animalDog->makeSound();
	animalAnimal->makeSound();
	
	std::cout << "\nTesting wrong animals:" << std::endl;
	const WrongAnimal* wrongAnimalAnimal = new WrongAnimal();
	const WrongAnimal* wrongAnimalCat = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();
	std::cout << wrongAnimalCat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongAnimalCat->makeSound();
	wrongCat->makeSound();
	wrongAnimalAnimal->makeSound();

	std::cout << "\nDestroying:" << std::endl;
	delete animalAnimal;
	delete animalDog;
	delete animalCat;
	delete wrongAnimalAnimal;
	delete wrongCat;
	delete wrongAnimalCat;
	return 0;
}