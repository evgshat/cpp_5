#include "Bureaucrat.hpp"

void	test1()
{
	try
	{
		Bureaucrat b("JENYA", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat b("JENYA", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test2()
{
	Bureaucrat b("JENYA", 2);
	b.increment();
	std::cout << b << std::endl;
	Bureaucrat c("JENYA", 149);
	c.decrement();
	std::cout << c << std::endl;
}

void test3()
{
	try
	{
		Bureaucrat tramp("Tramp", 149);
		Form popcorn("POP", 150, 150);
		std::cout << tramp << std::endl;
		std::cout << popcorn << std::endl;
		tramp.increment();
		tramp.signForm(popcorn);
		std::cout << tramp << std::endl;
		std::cout << popcorn << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
	std::cout << "test_1" << std::endl;
	test1();
	std::cout << "\n" << std::endl;
	std::cout << "test_2" << std::endl;
	test2();
	std::cout << "\n" << std::endl;
	std::cout << "test_3" << std::endl;
	test3();
}
