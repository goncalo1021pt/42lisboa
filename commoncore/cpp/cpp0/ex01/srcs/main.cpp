#include <PhoneBook.hpp>

void safeGetLine(t_string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "EOF detected, exiting..." << std::endl;
		exit(0);
	}
}

void replaceTabs(t_string &input)
{
	for (size_t ctd = 0; ctd < input.length(); ctd++)
	{
		if (input[ctd] == '\t')
			input[ctd] = ' ';
	}
}

void getInput(t_string &input)
{
	safeGetLine(input);
	if (input.empty())
		std::cout << "Input cannot be empty" << std::endl;
	else
		replaceTabs(input);
}

int main()
{
	PhoneBook phoneBook;
	t_string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		safeGetLine(command);
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
