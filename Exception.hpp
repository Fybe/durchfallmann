#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(std::string exceptionMessage);
	virtual const char *what() const noexcept;

private:
	std::string exceptionMessage;
};
