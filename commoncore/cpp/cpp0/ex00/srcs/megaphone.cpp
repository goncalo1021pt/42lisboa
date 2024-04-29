#include "../includes/megaphone.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int ctd = 1; ctd < argc; ctd++)
			for (int ctd2 = 0; argv[ctd][ctd2]; ctd2++)
				std::cout << (char)toupper(argv[ctd][ctd2]);
	std::cout << std::endl;
	return 0;
}