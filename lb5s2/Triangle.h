#pragma once

#define _USE_MATH_DEFINES

#include <cmath>

class Triangle {

private:

	bool ex_condition(float a, float b, float c);
	void Calculations();

protected:

	float notused;

	float angle_A, angle_B, angle_C;

	float side_a, side_b, side_c;

	float Perimetr;

	void CalculateAngles();

public:

	Triangle();
	Triangle(float a_side, float b_side, float c_side);

	void show();
	void CalculatePerimetr();
	
	// Без ссылки дабы не было возможнсти изменить значение
	float operator[](char factor);

	void ChangeSide(float factor, char side);
  
};

