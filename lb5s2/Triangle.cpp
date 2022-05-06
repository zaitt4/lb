#define _USE_MATH_DEFINES


#include "Triangle.h"
#include "Equilateral.h"
#include <iostream>
#include <cmath>


void Triangle::Calculations() {

	CalculateAngles();
	CalculatePerimetr();
}


bool Triangle::ex_condition(float a, float b, float c) {

	if (a + b > c && c + b > a && a + c > b)

		return true;
	
	return false;
}


void Triangle::CalculateAngles() {

	angle_A = acos((pow(side_c, 2) + pow(side_b, 2) - pow(side_a, 2)) / (2 * side_b * side_c));
	angle_A = angle_A * 180 / M_PI;

	angle_B = acos((pow(side_c, 2) + pow(side_a, 2) - pow(side_b, 2)) / (2 * side_a * side_c));
	angle_B = angle_B * 180 / M_PI;

	angle_C = acos((pow(side_a, 2) + pow(side_b, 2) - pow(side_c, 2)) / (2 * side_b * side_a));
	angle_C = angle_C * 180 / M_PI;
}


Triangle::Triangle() {

	side_a = 1;
	side_b = 1;
	side_c = M_SQRT2;

	Calculations();
}


Triangle::Triangle(float a_side, float b_side, float c_side) : Triangle() {

	if (ex_condition(a_side, b_side, c_side) == false) {

		printf("Стороны не удовлетворяют системе {a + b > c; a + c > b; b + c > a;\n\
				Присвоены стандартные значения (1;1;sqrt(2))\n");

	}

	else {

		side_a = a_side;
		side_b = b_side;
		side_c = c_side;

		Calculations();
	}
}


void Triangle::CalculatePerimetr() {

	Perimetr = side_a + side_b + side_c;
}


void Triangle::show() {

	printf("\nA = %.2f\nB = %.2f\nC = %.2f\n\nPerimetr = %.2f\n\nangle_A = %.2f\nangle_B = %.2f\nangle_C = %.2f\n",\
		  side_a, side_b, side_c, Perimetr, angle_A, angle_B, angle_C);
}


float Triangle::operator[](char factor) {
	
	switch (factor) {

	default:

		return notused = NULL;

	case('a'):

		return side_a;

	case('b'):

		return side_b;

	case('c'):

		return side_c;

	case('A'):

		return angle_A;

	case('B'):

		return angle_B;

	case('C'):

		return angle_C;
	}
}


void Triangle::ChangeSide(float factor, char side) {

	switch (side) {

	case('a'):

		if (ex_condition(factor, side_b, side_c) == false) {

			printf("Стороны не удовлетворяют системе {a + b > c; a + c > b; b + c > a;\n");
		}

		else {

			side_a = factor;
		}

		break;

	case('b'):

		if (ex_condition(side_a, factor, side_c) == false) {

			printf("Стороны не удовлетворяют системе {a + b > c; a + c > b; b + c > a;\n");
		}

		else {

			side_b = factor;
		}

		break;

	case('c'):

		if (ex_condition(side_a, side_b, factor) == false) {

			printf("Стороны не удовлетворяют системе {a + b > c; a + c > b; b + c > a;\n");
		}

		else {

			side_c = factor;
		}

		break;
	}

	Calculations();
}
