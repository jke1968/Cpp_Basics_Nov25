#include "FullyBookedException.h"

FullyBookedException::FullyBookedException(const std::string& message)
	: std::exception{message.c_str()}
{
}
