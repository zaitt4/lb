#include "Equilateral.h"
#include <iostream>


void Equilateral::EqCalculations() {

	CalculateArea();
	CalculateAngles();
	CalculatePerimetr();
}


void Equilateral::ShowArea() {

	printf("Area = %.2f", area);
}


float Equilateral::getArea() {

	return area;
}


void Equilateral::CalculateArea() {

	area = (pow(side_a, 2) * sqrt(3)) / 4;
}


Equilateral::Equilateral() : Triangle(1,1,1) {

	CalculateArea();
}


Equilateral::Equilateral(float side) : Triangle(side, side, side) {
	
	CalculateArea();
}


void Equilateral::ChangeSide(float factor) {

	side_a = factor;
	side_b = factor;
	side_c = factor;

	EqCalculations();
}
