#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "includes.hpp"

class Contact
{
	private:
		t_string _first_name;
		t_string _last_name;
		t_string _nickname;
		t_string _darkest_secret;
		t_string _phone_number;
	public:
		Contact();
		~Contact();
		bool SetFirstName(t_string firstName);
		bool SetLastName(t_string lastName);
		bool SetNickname(t_string nickname);
		bool SetDarkestSecret(t_string darkestSecret);
		bool SetPhoneNumber(t_string phoneNumber);
		t_string GetFirstName(void);
		t_string GetLastName(void);
		t_string GetNickname(void);
		t_string GetDarkestSecret(void);
		t_string GetPhoneNumber(void);
		void PrintContact(void);
};


#endif