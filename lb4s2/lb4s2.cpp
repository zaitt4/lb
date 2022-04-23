#include <stdio.h>
#include "Fraction.h"
#include <iostream>
#include <windows.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void Color(int factor) {

	SetConsoleTextAttribute(handle, factor);
}


int main() {

	Color(15);
	setlocale(LC_ALL, "ru");

	Color(12);
	printf("Декремент:\n");

	Color(15);

	Fraction smfr(16, 7);

	smfr--;

	smfr.ShowFraction();

	--smfr;

	smfr.ShowFraction();

	Color(10);
	printf("\nСложение\n");

	Color(15);
	Fraction scfr(5, 6, -1);

	smfr.ShowFraction();
	Fraction sum = smfr + scfr;

	Color(5);
	printf("\nУмножение\n");

	Color(15);

	Fraction fr(11, 3);
	Fraction sc(2, 5);

	Fraction dob = fr * sc;

	Color(3);
	printf("\nСравнение (%d/%d == %d/%d)\n\n", fr.getNum(), fr.getDenum(), sc.getNum(), sc.getDenum());

	Color(15);

	std::cout << "Результат сравнение: " << (fr == sc) << "\n";


	Fraction sccp(4,10);

	Color(3);

	printf("\nСравнение (%d/%d == %d/%d)\n\n", sccp.getNum(), sccp.getDenum(), sc.getNum(), sc.getDenum());

	Color(15);

	std::cout << "Результат сравнение: " << (sccp == sc) << "\n";

	
	Color(4);

	printf("\nСравнение (%d/%d != %d/%d)\n\n", sccp.getNum(), sccp.getDenum(), sc.getNum(), sc.getDenum());

	Color(15); 

	std::cout << "Результат сравнение: " << (sccp != sc) << "\n";


	Color(12);
	printf("\nСравнение (%d/%d != %d/%d)\n\n", sccp.getNum(), sccp.getDenum(), fr.getNum(), fr.getDenum());

	Color(15);

	std::cout << "Результат сравнение: " << (sccp != fr) << "\n";

	Color(13);

	printf("\nПрисваивание (sccp(%d/%d) = fr(%d/%d))\n", sccp.getNum(), sccp.getDenum(), fr.getNum(), fr.getDenum());

	Color(15);
	
	sccp.ShowFraction();

	sccp = fr;

	sccp.ShowFraction();
}
