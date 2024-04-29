#include <PhoneBook.hpp>

int main()
{
	PhoneBook phoneBook;
	t_string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phoneBook.AddContact();
		else if (command == "SEARCH")
			phoneBook.SearchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
}
