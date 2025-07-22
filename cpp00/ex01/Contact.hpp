/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:07:10 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 19:29:29 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		string m_firstName;
		string m_lastName;
		string m_phoneNumber;
		time_t m_createdAt;
	public:
		Contact();
		Contact(string &firstName, string &lastName, string &phoneNumber);
		~Contact();
		string getFirstName();
		string getLastName();
		string getPhoneNumber();
		time_t getCratedAt();
};

#endif