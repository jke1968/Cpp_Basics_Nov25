#pragma once
#include <exception>
#include <string>
class FullyBookedException : public std::exception
{
public:
	FullyBookedException(const std::string& message);
};

