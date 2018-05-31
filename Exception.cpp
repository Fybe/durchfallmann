#include "Exception.hpp"

Exception::Exception(std::string exceptionMessage)
	: exceptionMessage(exceptionMessage)
{}

const char *Exception::what() const noexcept
{ return exceptionMessage.c_str(); }
