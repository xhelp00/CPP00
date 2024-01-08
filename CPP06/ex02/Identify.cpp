#include "Identify.hpp"

Base::~Base()
{}

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (std::cout << "A created" << std::endl, new A);
		case 1:
			return (std::cout << "B created" << std::endl, new B);
		case 2:
			return (std::cout << "C created" << std::endl, new C);
		default:
			return (NULL);
	}
}

void identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr) != NULL)
		std::cout << "A identified using cast to pointer" << std::endl;
	else if (dynamic_cast<B*>(ptr) != NULL)
		std::cout << "B identified using cast to pointer" << std::endl;
	else if (dynamic_cast<C*>(ptr) != NULL)
		std::cout << "C identified using cast to pointer" << std::endl;
}

void identify(Base &ref)
{
	try 
	{
		A& test = dynamic_cast<A&>(ref);
		std::cout << "A identified using cast to reference" << std::endl;
		(void)test;
	}
	catch(const std::exception& e) {}
	
	try 
	{
		B& test = dynamic_cast<B&>(ref);
		std::cout << "B identified using cast to reference" << std::endl;
		(void)test;
	}
	catch( const std::exception& e ) {}
	
	try 
	{
		C& test = dynamic_cast<C&>(ref);
		std::cout << "C identified using cast to reference" << std::endl;
		(void)test;
	}
	catch( const std::exception& e ) {}
}