#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <algorithm>
# include <limits>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void get_data();

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void execute(int argc,char **argv);
		void outputData(std::string date, double btc_data);
};
#endif
