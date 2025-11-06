/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:56:45 by marcnava          #+#    #+#             */
/*   Updated: 2025/10/28 14:30:46 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string m_name;
		Weapon &m_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack() const;
};

#endif
