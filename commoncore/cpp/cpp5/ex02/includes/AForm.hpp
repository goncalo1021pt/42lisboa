#ifndef Aform_HPP
#define Aform_HPP

# include <iostream>

typedef std::string t_string;

class Bureaucrat;

class AForm {
	private:
		const t_string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(t_string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& src);
		~AForm();
		AForm &operator=(const AForm& src);
		void beSigned(const Bureaucrat &bureaucrat);
		t_string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void checkExecution(const Bureaucrat &executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : std::exception {
			public:
				const char *what() const throw();
		};

		class FormAlreadySignedException : std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
