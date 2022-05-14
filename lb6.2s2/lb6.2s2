#include <iostream>
#include <ctime>
#include "Segment.h"
#include "Logger.h"

int Segment::count = 0;

void NotLogged() {

	Segment a("DELETED OBJECT", 3, 4, 8, 2);
}

int main() {

	setlocale(LC_ALL, "ru");

	Segment a("new line");

	a.set_x1(12);
	a.set_y2(0);
	a.set_x2(6);
	a.set_y2(231);

	NotLogged();

	Segment b("ex,p", 4, 0, 0, 1);
	
	Logger::saveLog();
}
