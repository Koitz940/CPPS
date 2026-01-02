/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:46:22 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 16:41:28 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	const std::string target;
	
	RobotomyRequestForm();

	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;
};