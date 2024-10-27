#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(t_string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if ( _gradeToExecute > 150 || _gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (_gradeToExecute < 0 || _gradeToSign < 0)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm &src) {
	if (this == &src)
		return *this;
	_signed = src._signed;
	return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	if (_signed) {
		throw AForm::FormAlreadySignedException();
	}
	_signed = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const {
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooHighException::what() const throw() {
	return "Exception: Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Exception: Grade too low";
}

const char * AForm::FormNotSignedException::what() const throw() {
	return "Exception: Form not signed";
}

const char * AForm::FormAlreadySignedException::what() const throw() {
	return "Exception: Form already signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form:\n" <<  "Name: " << form.getName() << "\nSigned: " << form.getSigned() << "\nGrade to sign: " << form.getGradeToSign() << "\nGrade to execute: " << form.getGradeToExecute();
	return out;
}

t_string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}
