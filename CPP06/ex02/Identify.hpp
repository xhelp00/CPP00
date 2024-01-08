#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <cstdlib>
#include <iostream>

//Including the typeinfo header is forbidden

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base *ptr);
void identify(Base &ref);

#endif