#include "pch.h"
#include "book.h"

Book::Book(std::string _name, std::string _code, int _count)
{
	name = _name;
	code = _code;
	count = _count;
}

Book::Book(std::string _name, std::string _code)
{
	name = _name;
	code = _code;
}

std::string Book::GetName()
{
	return name;
}

std::string Book::GetCode()
{
	return code;
}

int Book::Count()
{
	return count;
}

void Book::incCount(int _count)
{
	if (_count >= 0)
		count += _count;
	else
	{
		std::string err = "Неверное значение";
		throw err;
	}
}

void Book::decCount(int _count)
{
	if (_count >= 0)
		count -= _count;
	else
	{
		std::string err = "Неверное значение";
		throw err;
	}
}

Book::~Book()
{
}
