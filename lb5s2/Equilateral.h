#pragma once

#include "Triangle.h"


class Equilateral :
    public Triangle {

private:

    float area;
    void CalculateArea();

public:

    Equilateral();
    Equilateral(float side);
    void ChangeSide(float factor);
    void EqCalculations();

    void ShowArea();
    float getArea();
};

