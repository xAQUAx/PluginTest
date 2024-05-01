#pragma once
#include <string>
#include <iostream>

class Figure
{
public:
	virtual double GetSquare() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string GetName() = 0;
	virtual ~Figure() {};
};

