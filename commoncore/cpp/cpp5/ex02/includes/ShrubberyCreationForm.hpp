#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);
};
#endif
