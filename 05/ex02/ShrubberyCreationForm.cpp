/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 02:01:52 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/31 02:01:52 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("sus")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called\n";
}

void ShrubberyCreationForm::exec() const
{
	std::string filename = this->target + "__shrubbery";
	std::ofstream myfile(filename.c_str());

	int amount = 2 + rand() % 4;
	int height = 8 + rand() % 10;
	int trunkLength = height / 2 + (height % 4) / 2 + 1;
	int trunkheight = height / 2;

	for (int i = 0; i < amount; ++i)
	{
		for (int j = height - 1; j >= 0; --j)
		{

			myfile << std::string(j, ' ');
			myfile << std::string(2 * (height - j) - 1, '#');
			myfile << "\n";
		}
		for (int j = 0; j < trunkheight; ++j)
		{
			myfile << std::string((height * 2) / 3, ' ');
			myfile << std::string(trunkLength, '|');
			myfile << "\n";
		}
		if (i + 1 != amount)
			myfile << "\n\n";
	}

	myfile.close();
}