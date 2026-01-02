/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:30:38 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 16:41:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	const std::string target;

	PresidentialPardonForm();

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		void execute(Bureaucrat const & executor) const;
};