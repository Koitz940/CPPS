/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:35:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 21:35:07 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		virtual AAnimal& operator=(const AAnimal& other);

		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound(void) const = 0;
		virtual Brain* getBrain() const = 0;
};