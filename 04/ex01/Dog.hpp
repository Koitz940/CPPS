/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:18:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:18:41 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	Brain* brain;
	public:
		Dog(void);
		Dog(const Dog&);
		~Dog();
		Animal& operator=(const Animal& other);

		void makeSound(void) const;
		Brain *getBrain(void) const;
};