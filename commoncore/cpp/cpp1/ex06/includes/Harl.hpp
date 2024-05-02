#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string levels[4];
		void (Harl:: *functions[4])();
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};



#endif