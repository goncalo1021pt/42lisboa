#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
	private:
		static AForm *(*formConstructors[3])(const std::string &target);
		static std::string formNames[3];
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern &operator=(const Intern& src);
		AForm *makeForm(std::string name, std::string target);
		

		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
#endif
