#pragma once
#include "Figure.h"

class Hexagon :
    public Figure
{
private:
    double a;
public:
    Hexagon();
    virtual double GetSquare();
    virtual double GetPerimeter();
    virtual std::string GetName();
    virtual ~Hexagon() {
        std::cout << "Hexagon destructor called!" << std::endl;
    }
};

