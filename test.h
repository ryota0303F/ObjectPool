#pragma once
#include <string>
#include <iostream>
class test
{
public:
	test()
	{
		data = "test";
		No = rand() % 10;
	}
	void Draw()
	{
		std::cout << data << " : " << No << "\n";
	}
private:
	std::string data;
	int No;
};

