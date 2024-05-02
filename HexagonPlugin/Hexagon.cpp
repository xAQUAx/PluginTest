#include "pch.h"
#include "Hexagon.h"

Hexagon::Hexagon()
{
	std::cout << "Side hexagon: ";
	std::cin >> this->a;
}

double Hexagon::GetSquare()
{
	return ((3 * pow(a, 2) * pow(3, 0.5)) / 2);
}

double Hexagon::GetPerimeter()
{
	return 6*this->a;
}

std::string Hexagon::GetName()
{
	return "Hexagon";
}