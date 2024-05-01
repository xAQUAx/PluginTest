#include "Circle.h"

Circle::Circle()
{
	std::cout << "Radius: ";
	std::cin >> this->r;
}

double Circle::GetSquare()
{
	return pi * r * r;
}

double Circle::GetPerimeter()
{
	return 2 * pi * r;
}

std::string Circle::GetName()
{
	return "Circle";
}