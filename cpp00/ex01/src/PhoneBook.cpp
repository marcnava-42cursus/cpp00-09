/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:35 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/22 21:11:01 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int oldest_contact_index(Contact contacts[MAX_CONTACTS])
{
	int oldest = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
		if (contacts[i].getCratedAt() < contacts[oldest].getCratedAt())
			oldest = i;
	return (oldest);
}

PhoneBook::PhoneBook()
{
	m_totalContacts = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact &contact)
{
	if (m_totalContacts < MAX_CONTACTS)
		contacts[m_totalContacts++] = contact;
	else
		contacts[oldest_contact_index(contacts)] = contact;
}

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret)
{
	Contact c = Contact(firstName, lastName, nickname,
		phoneNumber, darkestSecret);
	addContact(c);
}

int PhoneBook::getNumberEntries()
{
	return m_totalContacts;
}
