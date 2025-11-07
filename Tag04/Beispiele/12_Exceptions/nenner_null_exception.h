#pragma once
#include <exception>
class nenner_null_exception : public std::exception
{
public:
	nenner_null_exception(char const* message);
};

