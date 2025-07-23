/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:48 by marcnava          #+#    #+#             */
/*   Updated: 2025/07/23 01:03:06 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using namespace std;

Contact::Contact()
{
	m_firstName = "";
	m_lastName = "";
	m_nickname = "";
	m_phoneNumber = "";
	m_darkestSecret = "";
	m_createdAt = (time(&m_createdAt));
}

Contact::Contact(string &firstName, string &lastName, string &nickname,
	string &phoneNumber, string &darkestSecret)
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

string Contact::getFirstName()
{
	return m_firstName;
}

string Contact::getLastName()
{
	return m_lastName;
}

string Contact::getNickname()
{
	return m_nickname;
}

string Contact::getPhoneNumber()
{
	return m_phoneNumber;
}

string Contact::getDarkestSecret()
{
	return m_darkestSecret;
}

time_t Contact::getCratedAt()
{
	return m_createdAt;
}
