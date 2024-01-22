#include "Span.hpp"

#include <cstdlib>		// For rand() and srand()
#include <ctime>		// For time()

int	main(void)
{
	{ //test from the subject
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(20000);
		try //adding range that is bigger than max size
		{
			{sp.addRange(1, 100000);}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try //adding negative number and checking spans
		{
			sp.addNumber(-2);
			sp.addNumber(2);
			sp.addNumber(-42);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	{
		Span sp = Span(10);
		try //empty vector
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try //invalid range
		{
			sp.addRange(100, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try //out of range index
		{
			sp.addNumber(42);
			std::cout << sp.getMember(2) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
return 0;
}