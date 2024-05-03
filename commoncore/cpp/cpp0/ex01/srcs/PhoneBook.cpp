#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	_contactCtd = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact GetContactInfo(void)
{
	Contact contact;
	std::string input;

	do {
		std::cout << "Enter first name: ";
		getInput(input);
	} while (!contact.SetFirstName(input));
	do {
		std::cout << "Enter last name: ";
		getInput(input);
	} while (!contact.SetLastName(input));
	do {
		std::cout << "Enter nickname: ";
		getInput(input);
	} while (!contact.SetNickname(input));
	do {
		std::cout << "Enter phone number: ";
		safeGetLine(input);
	} while (!contact.SetPhoneNumber(input));
	do {
		std::cout << "Enter darkest secret: ";
		getInput(input);
	} while (!contact.SetDarkestSecret(input));
	return contact;
}

void PhoneBook::AddContact()
{
	Contact contact = GetContactInfo();
	_contacts[_contactCtd % 8] = contact;
	_contactCtd++;
	if (_contactCtd > 15)
		_contactCtd = 8;
}

void PhoneBook::SearchContact()
{
	t_string temp;

	for (int ctd = 0; ctd < _contactCtd && ctd < 8; ctd++) {
		std::cout << std::setw(10) << ctd << "|";
		temp = _contacts[ctd].GetFirstName();
		temp = temp.length() > 10 ? temp.substr(0, 9) + "." : temp;
		std::cout << std::setw(10) << temp << "|";
		temp = _contacts[ctd].GetLastName();
		temp = temp.length() > 10 ? temp.substr(0, 9) + "." : temp;
		std::cout << std::setw(10) << temp << "|";
		temp = _contacts[ctd].GetNickname();
		temp = temp.length() > 10 ? temp.substr(0, 9) + "." : temp;
		std::cout << std::setw(10) << temp << std::endl;
	}
	if (_contactCtd == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}
	while (1)
	{
		std::cout << "Enter index of contact: ";
		safeGetLine(temp);
		if (temp.length() != 1 || temp[0] < '0' || temp[0] > '7' || temp[0] - '0' >= _contactCtd)
			std::cout << "Invalid index" << std::endl;
		else
			break;
	}
	_contacts[temp[0] - '0'].PrintContact();
}