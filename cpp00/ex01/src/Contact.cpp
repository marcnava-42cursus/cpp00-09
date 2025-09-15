/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:48 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/22 21:10:35 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	m_firstName = "";
	m_lastName = "";
	m_nickname = "";
	m_phoneNumber = "";
	m_darkestSecret = "";
	m_createdAt = (time(&m_createdAt));
}

Contact::Contact(std::string &firstName, std::string &lastName, std::string &nickname,
	std::string &phoneNumber, std::string &darkestSecret)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_nickname = nickname;
	m_phoneNumber = phoneNumber;
	m_darkestSecret = darkestSecret;
	m_createdAt = (time(&m_createdAt));
}

Contact::~Contact() {}

// Getter / Setter

std::string Contact::getFirstName()
{
	return m_firstName;
}

std::string Contact::getLastName()
{
	return m_lastName;
}

std::string Contact::getNickname()
{
	return m_nickname;
}

std::string Contact::getPhoneNumber()
{
	return m_phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return m_darkestSecret;
}

time_t Contact::getCratedAt()
{
	return m_createdAt;
}
