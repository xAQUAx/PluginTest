#pragma once
#include "Figure.h"

class Rectangl :
    public Figure
{
private:
    double a, b;
public:
    Rectangl();
    virtual double GetSquare();
    virtual double GetPerimeter();
    virtual std::string GetName();
    virtual ~Rectangl() {
        std::cout << "Rectangle destructor called!" << std::endl;
    }
};

