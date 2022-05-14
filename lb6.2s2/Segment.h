#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef double Lf;

class Segment {

	/*
		b-  begin
		e-  end
		m-  middle
	*/

	Lf bx, by, ex, ey, mx, my, lenth;

	static int count;

	double notused = NULL;

	int number;

	char Time[40];
	char name[64];

	void Calculations();

		void Middle();
		void Lenth();

public:
	~Segment();
	Segment(const char* name, Lf x1 = 0, Lf y1 = 0, Lf x2 = 0, Lf y2 = 0);

	char* getName();
	int getNumber();
	static int getCount();

	void set_x1(double num);
	void set_x2(double num);
	void set_y1(double num);
	void set_y2(double num);

	double get_x1();
	double get_x2();
	double get_y1();
	double get_y2();
	double get_midy();
	double get_midx();
	double get_lenth();
};
