/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:40:20 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:40:20 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain
{
	std::string ideas[100];
	unsigned int size;

	public:

		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		Brain& operator=(const Brain& other);
		
		void addIdea(std::string idea);
		const std::string& getIdea(unsigned int index) const;
};