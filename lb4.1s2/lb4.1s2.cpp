#include <iostream>
#include <Windows.h>
#include "Segment.h"


Segment* square_maker(Segment source);


int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	Segment xf(-5, -4, -3, -2);

	Segment* Square = square_maker(xf);
}


//Создание квадрата путём поворотов source на 90 градусов
Segment* square_maker(Segment source) {

	Segment* square = new Segment[4];


	// 1
	square[0] = source;

	source.CopyToComment("1 сторона квадрата");

	printf("\t1 сторона\n");

	source.show_info();


	// 2
	Segment second_side(source);

	second_side(0, 0, 90);

	second_side.CopyToComment("2 сторона квадрата");

	printf("\n\t2 сторона\n");

	second_side.show_info(); 

	square[1] = second_side;


	// 3
	//Ракировочка, меняю местами начало и конец отрезка, что бы не было необходимости смещать отрезок для поворота
	Segment third_side(second_side[3], second_side[4], second_side[1], second_side[2]);

	third_side(0, 0, 90);

	printf("\n\t3 сторона\n");
	
	third_side.CopyToComment("3 сторона квадрата");

	third_side.show_info();

	square[2] = third_side;


	// 4
	Segment fourth_side(third_side[3], third_side[4], third_side[1], third_side[2]);

	fourth_side(0, 0, 90);

	printf("\n\t4 сторона\n");

	fourth_side.CopyToComment("4 сторона квадрата");

	square[3] = fourth_side;

	fourth_side.show_info();

	return square;
}
