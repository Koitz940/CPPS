/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:20:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/30 22:20:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("sus"), toGrade(150), toExecute(150)
{
	std::cout << "Form default Constructor called\n";
	this->Signed = false;
}

Form::~Form()
{
	std::cout << "Form Destructor called\n";
}

Form::Form(const std::string& name, unsigned int toGrade, unsigned int toExecute): name(name), toGrade(toGrade), toExecute(toExecute)
{
	std::cout << "Form Parameter Constructor called\n";
	if (toGrade < Form::max)
		throw(GradeTooHighException("Attempted to create a Form with a Grade higher than the maximum"));
	if (toExecute < Form::max)
		throw(ExecTooHighException("Attempted to create a Form with an Exec Value higher than the maximum"));
	if (toGrade > Form::min)
		throw(GradeTooLowException("Attempted to create a Form with a Grade lower than the minimum"));
	if (toExecute > Form::min)
		throw(ExecTooHighException("Attempted to create a Form with an Exec Value lower than the minimum"));
	this->Signed = false;
}

Form::Form(const Form& other): name(other.name), toGrade(other.toGrade), toExecute(other.toExecute)
{
	std::cout << "Form copy Constructor called\n";
	this->Signed = other.Signed;
} 
Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assign Constructor called\n";
	this->Signed = other.Signed;
	return (*this);
}

const std::string& Form::getName() const
{
	return this->name;
}

bool Form::isSigned() const
{
	return this->Signed;
}

unsigned int Form::getToGrade() const
{
	return this->toGrade;
}

unsigned int Form::getToExecute() const
{
	return this->toExecute;
}

bool Form::beSigned(const Bureaucrat& dude)
{
	if (this->Signed)
		throw(GradeTooLowException("because it was already signed"));
	if (this->toGrade < dude.getGrade())
		throw(GradeTooLowException("because their grade is too low"));
	this->Signed = true;
	return false;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (this->msg);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

const char* Form::ExecTooLowException::what() const throw()
{
	return (this->msg);
}

const char* Form::ExecTooHighException::what() const throw()
{
	return (this->msg);
}

Form::GradeTooHighException::GradeTooHighException(const char* msg): msg(msg) {}
Form::GradeTooLowException::GradeTooLowException(const char* msg): msg(msg) {}
Form::ExecTooHighException::ExecTooHighException(const char* msg): msg(msg) {}
Form::ExecTooLowException::ExecTooLowException(const char* msg): msg(msg) {}


std::ostream&	operator<<(std::ostream& out, Form& b)
{
	out << "Form: " << b.getName() << ", to grade: " << b.getToGrade() << ", to execute: " << b.getToExecute();
	return out;
}