#ifndef INCLUDES_H
# define INCLUDES_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
using std::cerr;
using std::endl;
typedef std::string t_string;

bool processInput(std::ifstream &infile, std::ofstream &outfile, t_string filename, std::ostringstream &ss);
void processOutput(std::ofstream &outfile, std::ostringstream &ss, t_string s1, t_string s2);

#endif