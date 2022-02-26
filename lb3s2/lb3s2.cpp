#include "Taper.h"
#include <iostream>
#include <windows.h>


int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);



	//Стандартный конструктор
	Taper Obj;

	Obj.setHeight();
	Obj.setRadius();
	Obj.ThrowMeSomeNumbers();



	//Массив Конусов
	int size;
	printf("Размер массива >> ");

	std::cin >> size;

	Taper* Cones = new Taper[size];

	for (int i = 0; i < size; i++) {

		Cones[i] = Taper((int)pow(i + 1, 2), (int)pow(i + 1, 3));

	}

	//Массив таки сохранился
	for (int i = 0; i < size; i++) {

		Cones[i].ThrowMeSomeNumbers();
	}

}
