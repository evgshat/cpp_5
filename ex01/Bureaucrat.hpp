#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		const Bureaucrat &operator= (const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);
		const std::string &getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form &form);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const _NOEXCEPT;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& copy);

#endif
