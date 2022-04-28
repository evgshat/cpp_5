#include "Bureaucrat.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl

Bureaucrat::Bureaucrat()
{
	LOG_FUNCTION;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	LOG_FUNCTION;
	*this = other;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &other)
{
	LOG_FUNCTION;
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

//

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade): name(Name), grade(Grade)
{
	LOG_FUNCTION;
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement()
{
	if (this->grade == 150)
		throw GradeTooHighException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& copy)
{
	os << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (os);
}
