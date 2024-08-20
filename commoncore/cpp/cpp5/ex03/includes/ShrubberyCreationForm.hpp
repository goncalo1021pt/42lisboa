#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

typedef std::string t_string;

class ShrubberyCreationForm : public AForm {
	private:
		t_string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(t_string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		static AForm* create(const std::string &target);

		void execute(const Bureaucrat &executor) const;

		class FileNotOpenException : public std::exception {
			public:
				const char *what() const throw();
		};
};
#endif
