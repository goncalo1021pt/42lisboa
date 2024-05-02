#include <includes.h>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " <<  "<filename> <s1> <s2>" << std::endl;
		return 1;
	}
	t_string filename = argv[1];
	t_string s1 = argv[2];
	t_string s2 = argv[3];
	std::ostringstream ss;
	std::ifstream infile;
	std::ofstream outfile;

	if (!processInput(infile, outfile, filename, ss))
		return 1;
	processOutput(outfile, ss, s1, s2);
	return 0;
}
