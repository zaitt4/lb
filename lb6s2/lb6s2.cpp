#include <iostream>
#include "Solid.h"


int main() {

	setlocale(LC_ALL, "ru");

    
	// "Абстрактный" указатель
	Solid* ptr;

    
	// Конус раудиусом 3 и высотой 4
	Cone newCone;

	ptr = &newCone;

	ptr->volume();


	// Куб стороной 4
	Cube newCube(4);

	ptr = &newCube;

	ptr->volume();

}
