/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:35 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 21:09:53 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_totalContacts = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact &contact)
{
	if (m_totalContacts < MAX_CONTACTS)
		contacts[m_totalContacts++] = contact;
}

void PhoneBook::addContact(string firstName,
	string lastName, string phoneNumber)
{
	if (m_totalContacts < MAX_CONTACTS)
		contacts[m_totalContacts++] = Contact(firstName, lastName, phoneNumber);
}

int PhoneBook::getNumberEntries() {}