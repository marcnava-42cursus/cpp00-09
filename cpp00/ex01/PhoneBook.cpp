/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:35 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 19:34:27 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_totalContacts = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact &contact) {}

void PhoneBook::addContact(string firstName,
	string lastName, string phoneNumber) {}

int PhoneBook::getNumberEntries() {}