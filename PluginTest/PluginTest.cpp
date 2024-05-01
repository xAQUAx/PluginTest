#include <iostream>
#include <vector>
#include <memory>

#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	std::vector<std::shared_ptr<Figure>> figures;
	int num;
	bool doInput = true;

	while (doInput == true)
	{
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Rectangle" << std::endl;
		std::cout << "2. Circle" << std::endl;

		std::cin >> num;
		switch (num)
		{
		case 0:
			doInput = false;
			break;
		case 1:
		{
			figures.push_back(std::make_shared<Rectangle>());
			break;
		}
		case 2:
		{
			figures.push_back(std::make_shared<Circle>());
			break;
		}
		default:
			std::cout << "Bad Figure number, try again" << std::endl;
			break;
		}
	}

	for (auto f : figures)
	{
		std::cout << f->GetName() << " Square: " << f->GetSquare() << ", Perimeter: " << f->GetPerimeter() << std::endl;
	}

	figures.clear();
	return 0;
}