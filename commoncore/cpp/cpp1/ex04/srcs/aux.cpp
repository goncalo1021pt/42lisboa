#include <includes.h>

bool processInput(std::ifstream &infile, std::ofstream &outfile, t_string filename, std::ostringstream &ss) {
	infile.open(filename.c_str());
	if (!infile) {
		std::cerr << "Error: " << filename << " not found." << std::endl;
		return false;
	}
	ss << infile.rdbuf();
	infile.close();
	outfile.open((filename + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error: " << filename << ".replace could not be created." << std::endl;
		return false;
	}
	return true;
}

void replaceAll(t_string &content, t_string s1, t_string s2) {
	for (size_t ctd = 0; (ctd = content.find(s1, ctd)) != t_string::npos; ctd += s2.length())
		content = content.substr(0, ctd) + s2 + content.substr(ctd + s1.length());
}

void processOutput(std::ofstream &outfile, std::ostringstream &ss, t_string s1, t_string s2) {
	t_string content = ss.str();
	replaceAll(content, s1, s2);
	outfile << content;
	outfile.close();
}
