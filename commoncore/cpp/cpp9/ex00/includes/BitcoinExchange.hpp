#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <algorithm>

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
};
#endif
