/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:31:45 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 20:59:26 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

using namespace std;

# include <iostream>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		int m_totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		Contact contacts[MAX_CONTACTS];
		void addContact(Contact &contact);
		void addContact(string firstName, string lastName, string phoneNumber);
		int getNumberEntries();
};

#endif