#include "Form.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl

Form::Form(): name(""), grade_sign(0), grade_ex(0), sign(false)
{
	LOG_FUNCTION;
}

Form::Form(const Form &other): name(other.name), grade_sign(other.grade_sign), grade_ex(other.grade_ex), sign(other.sign)
{
	LOG_FUNCTION;
}

const Form &Form::operator= (const Form &other)
{
	LOG_FUNCTION;
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

Form::~Form()
{

}

//

Form::Form(const std::string &Name, int Grade_sign, int Grade_ex, bool Sign): name(Name), grade_sign(Grade_sign), grade_ex(Grade_ex), sign(Sign)
{
	LOG_FUNCTION;
	if (grade_ex < 1 or grade_sign < 1)
		throw GradeTooHighException();
	else if (grade_ex > 150 or grade_sign > 150)
		throw GradeTooLowException();
}

const std::string &Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int Form::getGradeSign() const
{
	return this->grade_sign;
}

int Form::getGradeEx() const
{
	return this->grade_ex;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() <= this->grade_sign)
		this->sign = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& copy)
{
	os << "And new " << copy.getName() << " form grade to sign " << copy.getGradeSign() << ", grade to execute " << copy.getGradeEx() << ", is signed " << copy.getSign();
	return (os);
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
