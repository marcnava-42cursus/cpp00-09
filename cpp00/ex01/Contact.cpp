/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:48 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 19:29:59 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "Contact.hpp"

Contact::Contact()
{
	m_firstName = "";
	m_lastName = "";
	m_phoneNumber = "";
	m_createdAt = (time(&m_createdAt));
}

Contact::Contact(string &firstName, string &lastName, string &phoneNumber)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_phoneNumber = phoneNumber;
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

string Contact::getPhoneNumber()
{
	return m_phoneNumber;
}

time_t Contact::getCratedAt()
{
	return m_createdAt;
}
