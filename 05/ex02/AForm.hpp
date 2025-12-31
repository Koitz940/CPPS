/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:35:01 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 23:35:01 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	const std::string name;
	bool Signed;
	const unsigned int toGrade;
	const unsigned int toExecute;

	static const unsigned int max = 1;
	static const unsigned int min = 150;

	protected:
		AForm();
		virtual void exec() const = 0;
	public:
		~AForm();
		AForm(const std::string& name, unsigned int toGrade, unsigned int toExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		const std::string& getName() const;
		bool isSigned() const;
		unsigned int getToGrade() const;
		unsigned int getToExecute() const;

		bool beSigned(const Bureaucrat& dude);
		void execute(Bureaucrat const & executor) const;

	class GradeTooHighException: public std::exception
	{
		const char* msg;
		public:
			const char* what() const throw();
			GradeTooHighException(const char* msg);
	};

	class GradeTooLowException: public std::exception
	{
		const char* msg;
		public:
			const char* what() const throw();
			GradeTooLowException(const char* msg);
	};

	class ExecTooLowException: public std::exception
	{
		const char* msg;
		public:
			const char* what() const throw();
			ExecTooLowException(const char* msg);
	};

	class ExecTooHighException: public std::exception
	{
		const char* msg;
		public:
			const char* what() const throw();
			ExecTooHighException(const char* msg);
	};
};

std::ostream&	operator<<(std::ostream& out, AForm& b);