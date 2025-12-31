/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:53:18 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 19:53:18 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	const std::string name;
	unsigned int grade;
	static const unsigned int max = 1;
	static const unsigned int min = 150;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string& name, unsigned int garde);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
	
		unsigned int getGrade() const;
		const std::string& getName() const;
		void gradeUp(unsigned int amount);
		void gradeUp();
		void gradeDown(unsigned int amount);
		void gradeDown();

		void SignForm(AForm& AForm) const;
		void executeForm(AForm const & form);

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, Bureaucrat& b);