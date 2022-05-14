#define _CRT_SECURE_NO_WARNINGS
#include "Segment.h"
#include "Logger.h"
#include <ctime>
#include <cstring>

struct tm* T;
const time_t timer = time(NULL);

Logger* Logger::pattrn = 0;
Logger* lg = Logger::getSample();
char** Logger::log = 0;


Segment::~Segment() {

	char none[8] = "~delete";

	Logger::addRecord(*this, none);
	count--;
}


Segment::Segment(const char* name, Lf x1, Lf y1, Lf x2, Lf y2) {

	bx = x1; ex = x2;
	by = y1; ey = y2;

	T = localtime(&timer);
	strftime(Time, 40, "%Y.%m.%d %H:%M:%S", T);

	number = ++count;

	Calculations();


	strcpy(this->name, name);
	char* log_attribute = new char[(sizeof(this->name) / 8) + 256];

	sprintf(log_attribute, "Object%dName: %s\n\ttime: %s\n\tbx: %f\n\tby: %f\n\tex: %f\n\tey: %f\n\tmx: %f\n\tmy: %f\n\tlenth: %f\n", \
		number, this->name, Time, bx, by, ex, ey, mx, my, lenth);

	Logger::addRecord(*this, log_attribute);
}


void Segment::Middle() {

	mx = (bx + ex) / 2;
	my = (by + ey) / 2;
}


void Segment::Lenth() {

	lenth = sqrt(pow(bx + ex, 2) + pow(by + ey, 2));
}


void Segment::Calculations() {

	Lenth();
	Middle();
}

void Segment::set_x1(double num) {
	
	bx = num;

	char* log_attribute = new char[256];

	Calculations();

	sprintf(log_attribute, "\t~bx: %f\n\t\t!mx -> %f\n\t\t!my -> %f\n\t\t!lenth -> %f\n", bx, mx, my, lenth);

	Logger::addRecord(*this, log_attribute);

	//printf("%s", log_attribute);
}


void Segment::set_x2(double num) {

	ex = num;

	char* log_attribute = new char[256];

	Calculations();

	sprintf(log_attribute, "\t~ex: %f\n\t\t!mx: %f\n\t\t!my: %f\n\t\t!lenth: %f\n", ex, mx, my, lenth);

	Logger::addRecord(*this, log_attribute);
	
}


void Segment::set_y1(double num) { 

	by = num;

	char* log_attribute = new char[256];


	Calculations();

	sprintf(log_attribute, "\t~by: %f\n\t\t!mx -> %f\n\t\t!my -> %f\n\t\t!lenth -> %f\n", by, mx, my, lenth);

	Logger::addRecord(*this, log_attribute);

}


void Segment::set_y2(double num) { 

	ey = num;

	char* log_attribute = new char[256];

	Calculations();

	sprintf(log_attribute, "\t~ey: %f\n\t\t!mx -> %f\n\t\t!my -> %f\n\t\t!lenth -> %f\n", ey, mx, my, lenth);

	Logger::addRecord(*this, log_attribute);

}



double Segment::get_x1()		 { return bx; }

double Segment::get_x2()		 { return ex; }

double Segment::get_y1()		 { return by; }

double Segment::get_y2()		 { return ey; }

double Segment::get_midx()		 { return mx; }

double Segment::get_midy()		 { return my; }

char* Segment::getName()		 { return name; }

int Segment::getCount()			 { return count; }

double Segment::get_lenth()		 { return lenth; }

int Segment::getNumber()		 { return number; }


