#include <Harl.h>

int main(int argc, char **argv) {
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "HARL can only complain using 1 star wars quote per time" << std::endl;
		return 1;
	}
	for (int ctd = 1; ctd < argc; ctd++)
		harl.complain(argv[ctd]);
	return 0;
}
