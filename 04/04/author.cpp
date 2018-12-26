#include "pch.h"
#include "author.h"

Author::Author(std::string _name, std::string _code)
{
	name = _name;
	code = _code;
}

std::string Author::GetName()
{
	return name;
}

std::string Author::GetCode()
{
	return code;
}

Author::~Author()
{
}
