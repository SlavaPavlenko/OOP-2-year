#pragma once
#include <string>
#include <vector>
#include "author.h"

class Book
{
private:
	std::string name;
	std::string code;
	int count;
public:
	Book(std::string _name, std::string _code, int _count);
	Book(std::string _name, std::string _code);
	std::string GetName();
	std::string GetCode();
	int Count();
	void incCount(int _count);
	void decCount(int _count);
	~Book();
};

