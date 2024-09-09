#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		BitcoinExchange exchange;
		exchange.execute(argc, argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
