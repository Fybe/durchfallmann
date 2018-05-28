#pragma once
#include <exception>
#include <string>

class ExceptionNoWindow : public std::exception
{
public:
	virtual const char *what() const noexcept;
};

extern ExceptionNoWindow noWindowException;
