#include "Exception.hpp"

// function definitions
const char *ExceptionNoWindow::what() const noexcept
{ return "window hasn't been created yet"; }


// exception definition
ExceptionNoWindow noWindowException;
