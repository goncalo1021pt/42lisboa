#ifndef form_HPP
#define form_HPP

# include <iostream>
# include "Bureaucrat.h"

typedef std::string t_string;

class Form {
	private:
		const t_string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(t_string name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		~Form();
		Form &operator=(const Form& src);
		void beSigned(const Bureaucrat &bureaucrat);
		t_string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};
#endif
