/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:16:19 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 20:16:19 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("sus")
{
	std::cout << "Default Bureaucrat constructor called\n";
	this->grade = 150; // Because I hate them
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): name(name)
{
	std::cout << "Parameter Bureaucrat constructor called\n";
	if (grade < Bureaucrat::max)
		throw(GradeTooHighException());
	else if (grade > Bureaucrat::min)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName())
{
	std::cout << "Copy Bureaucrat constructor called\n";
	this->grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assign Bureaucrat constructor called\n";
	this->grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destructor called\n";
}

unsigned int Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string& Bureaucrat::getName() const
{
	return this->name;
}

void Bureaucrat::gradeUp(unsigned int amount)
{
	if (this->grade < Bureaucrat::max + amount)
		throw(GradeTooHighException());
	this->grade -= amount;
}

void Bureaucrat::gradeUp()
{
	if (this->grade == Bureaucrat::max)
		throw(GradeTooHighException());
	--this->grade;
}

void Bureaucrat::gradeDown(unsigned int amount)
{
	if (this->grade + amount > Bureaucrat::min)
		throw(GradeTooLowException());
	this->grade += amount;
}

void Bureaucrat::gradeDown()
{
	if (this->grade == Bureaucrat::min)
		throw(GradeTooLowException());
	++this->grade;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureauctrat grade " << b.getGrade();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade change would result in a grade higher than the maximum");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade change would result in a grade lower than the maximum");
}

void Bureaucrat::SignForm(AForm& form) const
{
	try
	{
		if (form.isSigned())
			throw(AForm::GradeTooLowException("because it was already signed"));
		if (form.getToGrade() < this->getGrade())
			throw(AForm::GradeTooLowException("because their grade is too low"));
		std::cout << this->getName() << " signed " << form.getName() << "\n";
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.checkConditions(*this);
		std::cout << this->getName() << " executed " << form.getName() << "\n";
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't execute " << form.getName() << " " << e.what() << '\n';
	}
	
}