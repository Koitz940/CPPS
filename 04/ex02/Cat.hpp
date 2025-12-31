/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:09:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:09:09 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	Brain* brain;
	public:
		Cat(void);
		Cat(const Cat&);
		~Cat();
		AAnimal& operator=(const AAnimal& other);
		Cat& operator=(const Cat& other);

		void makeSound(void) const;
		Brain	*getBrain(void) const;
};