#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(t_string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (other._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (other._grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	_grade = other._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(int amount) {
	_grade -= amount;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(int amount) {
	_grade += amount;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {
	if (form.getGradeToSign() < _grade)
		throw Form::GradeTooLowException();
	form.beSigned(*this);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}