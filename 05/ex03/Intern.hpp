/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:37:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/31 15:37:09 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern
{
	AForm* createRobot(const std::string &target) const;
	AForm* createSrhub(const std::string &target) const;
	AForm* createPres(const std::string &target) const;

	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& name, const std::string& target);

	class FormDoesNotExist: public std::exception
	{
		public:
			const char* what() const throw();
	};
};
