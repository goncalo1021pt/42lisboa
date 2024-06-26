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
	for (int ctd = 0; ctd < 4; ctd++) {
		if (level == levels[ctd]) {
			(this->*functions[ctd])();
			return;
		}
	}
	std::cout << "Invalid: HARL forgot more star wars quotes" << std::endl;
}
