/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:21:35 by marcnava          #+#    #+#             */
/*   Updated: 2025/10/28 14:47:00 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->m_weapon = NULL;
	this->m_name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->m_weapon = &weapon;
}

void HumanB::attack() const
{
	if (!this->m_weapon)
	{
		std::cout << this->m_name << " has not any weapon" << std::endl;
		return ;
	}
	std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}
