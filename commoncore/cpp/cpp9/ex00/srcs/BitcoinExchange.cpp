#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	get_data();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
	return *this;
}

void BitcoinExchange::get_data() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Error data.csv: file not found");
	}

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Error data.csv: invalid file format");
	}

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		double btc_data;
		
		std::getline(iss, date, ',');
		iss >> btc_data;
		_data[date] = btc_data;
	}
}

void removeSpaces(std::string &str) {
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

bool dateIsValid(std::string date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 6).c_str());
	int day = std::atoi(date.substr(8, 9).c_str());
	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return false;
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			if (day > 29)
				return false;
		}
		else if (day > 28)
			return false;
	}
	return true;
}

bool checkline(std::string line)
{
	if (line.empty())
		return false;
	if (line.find_first_of("|") == std::string::npos)
		return false;
	std::string date = line.substr(0, line.find_first_of("|"));
	std::string value = line.substr(line.find_first_of("|") + 1);
	if (date.empty() || value.empty())
		return false;
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return false;
	if (value.find_first_not_of("0123456789.-") != std::string::npos)
		return false;
	return true;
}

void parseInput(std::string &line, std::ifstream &file, int argc, char **argv)
{
	if (argc != 2) {
		throw std::runtime_error("Usage: ./btc [filename]");
	}
	file.open(argv[1]);
	if (!file.is_open()) {
		throw std::runtime_error("Error: file not found");
	}
	std::getline(file, line);
	if (line != "date | value") 
		throw std::runtime_error("Error: invalid file format");
}

void BitcoinExchange::outputData(std::string date, double btc_data) {
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (_data[it->first] * btc_data > std::numeric_limits<int>::max()) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	std::cout << date << " => " << btc_data << " = " << _data[it->first] * btc_data << std::endl;
}

void BitcoinExchange::execute(int argc, char **argv) {
	std::ifstream file;
	std::string line;
	parseInput(line, file, argc, argv);

	while (std::getline(file, line)) {
		std::string parsedLine = line;
		removeSpaces(parsedLine);
		if (!checkline(parsedLine))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::istringstream iss(parsedLine);
		std::string date;
		double btc_data;

		std::getline(iss, date, '|');
		iss >> btc_data;
		if (date < "2009-01-02" || !dateIsValid(date)) {
			std::cerr << "Error: date out of range => " << line << std::endl;
			continue;
		}
		if (btc_data < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		outputData(date, btc_data);
	}
	file.close();
}