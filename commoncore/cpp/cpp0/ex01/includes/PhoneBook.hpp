#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "includes.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _contactCtd;
	public:
		void AddContact(void);
		void SearchContact(void);
		PhoneBook();
		~PhoneBook();
};


#endif