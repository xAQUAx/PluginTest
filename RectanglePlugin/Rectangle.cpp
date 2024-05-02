#include "Rectangle.h"
#include "pch.h"

Rectangl::Rectangl()
{
	std::cout << "Side A: ";
	std::cin >> this->a;
	std::cout << "Side B: ";
	std::cin >> this->b;
}

double Rectangl::GetSquare()
{
	return a * b;
}

double Rectangl::GetPerimeter()
{
	return 2 * a + 2 * b;
}

std::string Rectangl::GetName()
{
	return "Rectangle";
}