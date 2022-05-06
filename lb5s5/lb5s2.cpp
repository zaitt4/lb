#include "Triangle.h"
#include "Equilateral.h"
#include <iostream>

Triangle builtEq(Triangle& victim);


int main() {

	setlocale(LC_ALL, "ru");
	Triangle obj(3,8,7);
	Equilateral eqobj(2);

	obj.ChangeSide(2, 'a');

	eqobj.ChangeSide(3);

	printf("Обьект типа Triangle:\n");
	obj.show();

	printf("\nОбъект типа Equilateral:\n");
	eqobj.show();
	printf("\n");
	eqobj.ShowArea();
	
	Triangle newEq = builtEq(obj);

	printf("\n\nПодстановка:\n");
	newEq.show();
    
}


Triangle builtEq(Triangle& victim) {

	float a = victim['a'], b = victim['b'], c = victim['c'];

	float factor = a;

	if (a > b && a > c) {
		
		factor;
	}

	else if (b > a && b > c) {

		factor = b;
	}

	else {

		factor = c;
	}

	Equilateral nwEq(factor);
	return nwEq;
}
