#include "Rectangle.h"
#include "pch.h"

Rectangle::Rectangle()
{
	std::cout << "Side A: ";
	std::cin >> this->a;
	std::cout << "Side B: ";
	std::cin >> this->b;
}

double Rectangle::GetSquare()
{
	return a * b;
}

double Rectangle::GetPerimeter()
{
	return 2 * a + 2 * b;
}

std::string Rectangle::GetName()
{
	return "Rectangle";
}