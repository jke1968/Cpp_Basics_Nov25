#include "nenner_null_exception.h"

nenner_null_exception::nenner_null_exception(char const* message)
	: std::exception{message}
{
}
