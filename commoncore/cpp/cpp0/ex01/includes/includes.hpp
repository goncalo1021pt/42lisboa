#ifndef INCLUDES_HPP
# define INCLUDES_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>
# include <cctype>

typedef	std::string t_string;

void safeGetLine(t_string &input);
void replaceTabs(t_string &input);
void getInput(t_string &input);

#endif