#include "A.h"
#include <iostream>
A::A() : i{0}
{
	std::cout << "ctor of A called" << std::endl;
}

A::~A()
{
	std::cout << "dtor of A called" << std::endl;
}
