#include <Harl.h>

int main(int argc, char **argv) {
	Harl harl;
	
	if (argc < 2) 
		return 1;
	for (int ctd = 1; ctd < argc; ctd++)
		harl.complain(argv[ctd]);
	return 0;
}
