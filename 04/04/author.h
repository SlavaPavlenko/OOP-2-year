#pragma once
#include <string>
class Author
{
private:
	std::string name;
	std::string code;
public:
	Author(std::string _name, std::string _code);
	std::string GetName();
	std::string GetCode();
	~Author();
};