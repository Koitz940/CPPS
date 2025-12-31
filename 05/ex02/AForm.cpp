/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:20:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/30 22:20:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("sus"), toGrade(150), toExecute(150)
{
	std::cout << "AForm default Constructor called\n";
	this->Signed = false;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called\n";
}

AForm::AForm(const std::string& name, unsigned int toGrade, unsigned int toExecute): name(name), toGrade(toGrade), toExecute(toExecute)
{
	std::cout << "AForm Parameter Constructor called\n";
	if (toGrade < AForm::max)
		throw(GradeTooHighException("Attempted to create a Form with a Grade higher than the maximum"));
	if (toExecute < AForm::max)
		throw(ExecTooHighException("Attempted to create a Form with an Exec Value higher than the maximum"));
	if (toGrade > AForm::min)
		throw(GradeTooLowException("Attempted to create a Form with a Grade lower than the minimum"));
	if (toExecute > AForm::min)
		throw(ExecTooHighException("Attempted to create a Form with an Exec Value lower than the minimum"));
	this->Signed = false;
}

AForm::AForm(const AForm& other): name(other.name), toGrade(other.toGrade), toExecute(other.toExecute)
{
	std::cout << "AForm copy Constructor called\n";
	this->Signed = other.Signed;
} 
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assign Constructor called\n";
	this->Signed = other.Signed;
	return (*this);
}

const std::string& AForm::getName() const
{
	return this->name;
}

bool AForm::isSigned() const
{
	return this->Signed;
}

unsigned int AForm::getToGrade() const
{
	return this->toGrade;
}

unsigned int AForm::getToExecute() const
{
	return this->toExecute;
}

bool AForm::beSigned(const Bureaucrat& dude)
{
	if (this->Signed)
		throw(GradeTooLowException("because it was already signed"));
	if (this->toGrade < dude.getGrade())
		throw(GradeTooLowException("because their grade is too low"));
	this->Signed = true;
	return false;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (this->msg);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

const char* AForm::ExecTooLowException::what() const throw()
{
	return (this->msg);
}

const char* AForm::ExecTooHighException::what() const throw()
{
	return (this->msg);
}

AForm::GradeTooHighException::GradeTooHighException(const char* msg): msg(msg) {}
AForm::GradeTooLowException::GradeTooLowException(const char* msg): msg(msg) {}
AForm::ExecTooHighException::ExecTooHighException(const char* msg): msg(msg) {}
AForm::ExecTooLowException::ExecTooLowException(const char* msg): msg(msg) {}

std::ostream&	operator<<(std::ostream& out, AForm& b)
{
	out << "AForm: " << b.getName() << ", to grade: " << b.getToGrade() << ", to execute: " << b.getToExecute();
	return out;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw(AForm::ExecTooLowException("because the form is not signed"));
	if (this->toExecute < executor.getGrade())
		throw(AForm::ExecTooLowException("because they do not have a high enough grade value"));
	this->exec();
}