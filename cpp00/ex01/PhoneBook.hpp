/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:31:45 by marcnava          #+#    #+#             */
/*   Updated: 2025/07/23 00:53:44 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

using namespace std;

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		int m_totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		Contact contacts[MAX_CONTACTS];
		void addContact(Contact &contact);
		void addContact(string firstName, string lastName, string nickname,
			string phoneNumber, string darkestSecret);
		int getNumberEntries();
};

#endif