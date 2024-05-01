#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{
private:
    double a, b;
public:
    Rectangle();
    virtual double GetSquare();
    virtual double GetPerimeter();
    virtual std::string GetName();
    virtual ~Rectangle() {
        std::cout << "Rectangle destructor called!" << std::endl;
    }
};

