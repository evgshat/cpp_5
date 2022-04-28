#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			grade_sign;
		const int			grade_ex;
		bool				sign;
	public:
		Form();
		Form(const Form& other);
		const Form& operator=(const Form& other);
		~Form();

		Form(const std::string &Name, int Grade_sign, int Grade_ex, bool Sign = false);
		const std::string &getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeEx() const;
		void beSigned(const Bureaucrat &bur);

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

std::ostream& operator<<(std::ostream& os, const Form& copy);

#endif
