/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:28:31 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 21:28:31 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define NUMBER_OF_AAnimalS 8

int main()
{
	AAnimal	*AAnimals[NUMBER_OF_AAnimalS];
	Brain	*brain;

	std::cout << "\nCreatig AAnimals' array\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_AAnimalS; i++)
	{
		if (i % 2 == 0)
			AAnimals[i] = new Dog();
		else
			AAnimals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "Assigning some ideas ti AAnimal[7]" <<std::endl;
	brain = AAnimals[7]->getBrain();
	brain->addIdea("I'm hungry");
	brain->addIdea("That's a strange idea I'm having");
	brain->addIdea("Ball!!!!!");
	brain->addIdea("Squirrel!!!!!");
	std::cout << "First idea of AAnimal[7]: " << brain->getIdea(0) << std::endl;

	std::cout << "\nAssigning AAnimal[7] to AAnimal[5]" << std::endl;
	*(AAnimals[5]) = *(AAnimals[7]);
	std::cout << "First idea of AAnimal[5]: " << AAnimals[5]->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nAdding different ideas to AAnimals[5] and AAnimals[7] (deep copy)" << std::endl;
	AAnimals[5]->getBrain()->addIdea("Last idea of AAnimals[5]");
	std::cout << "Last idea of AAnimal[5]: " << AAnimals[5]->getBrain()->getIdea(4) << std::endl;
	AAnimals[7]->getBrain()->addIdea("Last idea of AAnimals[7]");
	std::cout << "Last idea of AAnimal[7]: " << AAnimals[7]->getBrain()->getIdea(4) << std::endl;
	
	std::cout << "\nDestructing AAnimals\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_AAnimalS; i++)
		delete AAnimals[i];
}