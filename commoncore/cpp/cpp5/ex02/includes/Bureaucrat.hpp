#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include "AForm.hpp"

typedef std::string t_string;

class Bureaucrat {
	private:
		t_string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(t_string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		t_string getName() const;
		int getGrade() const;
		void incrementGrade(int amount);
		void decrementGrade(int amount);
		void signForm(class AForm &form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
