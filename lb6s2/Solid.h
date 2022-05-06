#pragma once

#include <iostream>


/*
	Solid = 0
	Cone,
	Cube.
*/


class Solid {

protected:

	float _volume;

public:

	virtual void volume() = 0;
	
}; 




class Cone :
	public Solid {

private:

	float height, radius, apothem;

	void Calculations() {

		apothem = sqrt(pow(height, 2) + pow(radius, 2));
		_volume = _volume = (3.14 * pow(radius, 2) * height) / 3; //Что бы не дублировался вывод, учитывая условие задачи
	}

public:

	void volume() {

		_volume = (3.14 * pow(radius, 2) * height) / 3;
		printf("Объем конуса: %.2f\n", _volume);
	}

        
	Cone() {

		height = 4;
		radius = 3;

		Calculations();
	}

        
	Cone(float height, float radius) {

		this->radius = radius;
		this->height = height;
		Calculations();
	}

        
	void setHeight(float height) {
		
		this->height = height;
		Calculations();
	}

        
	void setRadius(float radius) {

		this->radius = radius;
		Calculations();
	}

        
	void show() {

		printf("\nКонус:\n\nВысота: %.2f\nРадиус: %.2f\nАпофема: %.2f\n\nОбъем: %.2f\n", height, radius, apothem, _volume);
	}

};




class Cube :
	public Solid {

private:

	float side;

public:


	void volume() {
		
		_volume = pow(side, 3);
		printf("Объем куба: %.2f\n", _volume);
	}

        
	Cube() {

		side = 1;
		_volume = pow(side, 3);
	}

        
	Cube(float side) {

		this->side = side;
		_volume = pow(side, 3);
	}

        
	void setSide(float side) {

		this->side = side;
	}

        
	void show() {

		printf("\nКуб:\n\nСторона: %.2f\n\nОбъем: %.2f\n", side, _volume);
	}
};

