#include <Contact.hpp>

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool Contact::SetFirstName(t_string content)
{
	if (content == "")
		return false;
	_first_name = content;
	return true;
}

bool Contact::SetLastName(t_string content)
{
	if (content == "")
		return false;
	_last_name = content;
	return true;
}

bool Contact::SetNickname(t_string content)
{
	if (content == "")
		return false;
	_nickname = content;
	return true;
}

bool Contact::SetDarkestSecret(t_string content)
{
	if (content == "")
		return false;
	_darkest_secret = content;
	return true;
}

bool Contact::SetPhoneNumber(t_string content)
{
	if (content == "")
		return false;
	_phone_number = content;
	return true;
}

t_string Contact::GetFirstName(void)
{
	return _first_name;
}

t_string Contact::GetLastName(void)
{
	return _last_name;
}

t_string Contact::GetNickname(void)
{
	return _nickname;
}

t_string Contact::GetDarkestSecret(void)
{
	return _darkest_secret;
}

t_string Contact::GetPhoneNumber(void)
{
	return _phone_number;
}

void Contact::PrintContact(void)
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}