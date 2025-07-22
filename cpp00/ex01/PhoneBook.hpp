/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:31:45 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 19:33:11 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

using namespace std;

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		int m_currentIndex;
		int m_totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact &contact);
		void addContact(string firstName, string lastName, string phoneNumber);
		int getNumberEntries();
};

#endif