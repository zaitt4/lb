#include "Taper.h"
#include <iostream>
#include <windows.h>


HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


//Цвет
void Color(_Color Factor) {

	SetConsoleTextAttribute(handle, Factor);
}


//Вывод адреса текущего объедка
void Taper::_this__out(_Color factor) {

	Color(factor);
	printf("%p ", this);

	Color(White);
}


//Копирование строк
void Taper::_strcpy(char* target, const char* victim) {

	for (int i = 0; i < strlen(victim); i++) {

		target[i] = victim[i];
	}
  
}


//Объем
float Taper::Volume() {

	return ((PI * pow(radius, 2) * height)/3);
}


//Площадь основания
float Taper::BaseArea() {

	return (PI * pow(radius, 2));
}


//Вывод всех значений
void Taper::ThrowMeSomeNumbers() {

	_base_area = BaseArea();
	volume = Volume();

	printf("\nОбъедок: ");

	_this__out(LGreen);

	Color(White);
	printf("аля ");

	Color(LGreen);
	printf("%s", Comment);

	Color(White);
	printf("\nВысота: %f\tРадиусик: %f\tПощадь Основаньица: %f\tОбъемчик: %f\n\n", height, radius, _base_area, volume);
  
}


//Стандартный конструктор
Taper::Taper() {

	printf("Вызван стандартный констриктор для ");

	_this__out(LRed);
	printf("\n");
  
}


//Конструктор радиуса и высоты
Taper::Taper(F radius, F height) {

	printf("\nВызван констриктор (радиус, высота) для ");

	Color(LRed);
	printf("%p\n", this);

	this->height = height;
	this->radius = radius;

	_base_area   = BaseArea();
	volume		   = Volume();
  
}


//Копировальный конструктор
Taper::Taper(const Taper &victim) {

	Color(LGreen);
	printf("\nВызван конструкторш копирования:\n\n");

	_this__out(LRed);

	Color(White);
	printf("<< ");

	Color(LRed);
	printf("%p\n", victim);

	Color(LRed);
	printf("%s ", this->Comment);

	Color(White);
	printf("<< ");

	Color(LRed);
	printf("%s\n", victim.Comment);
	


	height		   =	victim.height;
	radius		   =	victim.radius;
	_base_area	 =	victim._base_area;
	volume		   =	victim.volume;

	_strcpy(this->Comment, victim.Comment);

}


//Деструктоид
Taper::~Taper() {

	Color(Red);
	printf("\nВызван деструктоид для ");

	_this__out(LRed);

	Color(Red);
	printf("аля ");

	Color(LRed);
	printf("%s\n", Comment);

	Color(White);

}


//Установка комментария
void Taper::setComment() {

	printf("Комментарий >> ");
	std::cin.getline(Comment, maxlenth);

}


//Установка комментария с параметром
void Taper::setComment(const char* Name) {

	_strcpy(Comment, Name);
  
}


//Установка высоты
void Taper::setHeight() {

	printf("       << Высота\r");
	std::cin >> height;

	while (std::cin.fail()) {

		std::cin.clear();
		std::cin.ignore(256,'\n');


		printf("       << Высота\r");
		std::cin >> height;
	}

}


//Установка радиуса
void Taper::setRadius() {


	printf("Радиус >> ");
	std::cin >> radius;

	while (std::cin.fail()) {

		std::cin.clear();
		std::cin.ignore(256, '\n');


		printf("Радиус >> ");
		std::cin >> radius;
	}

}


//Гетор высотки
float Taper::getHeight() {

	return height;
}


//Гетор радиуса
float Taper::getRadius() {

	return radius;
}

