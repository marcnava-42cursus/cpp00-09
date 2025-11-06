/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:17:34 by marcnava          #+#    #+#             */
/*   Updated: 2025/10/28 14:46:12 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_weapon(weapon)
{
	this->m_name = name;
}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}
