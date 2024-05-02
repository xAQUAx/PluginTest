#pragma once
#include "Figure.h"

class Circle :
    public Figure
{
private:
    double r;
    const double pi = 3.14;
public:
    Circle();
    virtual double GetSquare();
    virtual double GetPerimeter();
    virtual std::string GetName();
    virtual ~Circle() {
        std::cout << "Circle destructor called!" << std::endl;
    }
};

