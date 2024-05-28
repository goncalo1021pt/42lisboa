#include "Form.h"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(t_string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

Form::~Form() {}

Form& Form::operator=(const Form &src) {
	if (this == &src)
		return *this;
	_signed = src._signed;
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char * Form::GradeTooHighException::what() const throw() {
	return "Exception: Grade too high";
}

const char * Form::GradeTooLowException::what() const throw() {
	return "Exception: Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	std
	return out;
}

t_string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}
