#include <Harl.h>

Harl::Harl() {
	functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG: you underestimate my power" << std::endl;
}

void Harl::info() {
	std::cout << "INFO: It's over, Anakin. I have the high ground!" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: Hello there!" << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is where the fun begins." << std::endl;
}

void Harl::complain(std::string level) {
	int ctd = -1;
	while (++ctd < 4)
		if (level == levels[ctd]) 
			break;
	switch (ctd)
	{
		// fallthrough
		case 0:
			(this->*functions[0])();
		// fallthrough
		case 1:
			(this->*functions[1])();
		// fallthrough
		case 2:
			(this->*functions[2])();
		// fallthrough
		case 3:
			(this->*functions[3])();
			break;
		default:
			std::cout << "Invalid: HARL forgot more star wars quotes" << std::endl;
	}
}
