#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator= (const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);
		const std::string &getName() const;
		int getGrade() const;
		void increment();
		void decrement();

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
