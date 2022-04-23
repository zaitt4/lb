#pragma once

#include <iostream>

class Segment {

		   float notused = 0;
			 
	float x1 = 0;		float x2 = 0;
	float y1 = 0;		float y2 = 0;

		     float lenth;

    float x_mid = 0;	float y_mid = 0;

		   char comment[256] = "N/A";

		void calculate_lenth();	

			void calculate_middle();
	

public:

	Segment(float x1, float y1, float x2, float y2);
			Segment(Segment& victim);
					Segment();
							~Segment();
									void show_info();

	friend std::ostream &operator<<(std::ostream &out, const Segment &victim);

		friend std::istream &operator>>(std::istream &inp, Segment &victim);

			float &operator [](int i);

				void operator()(float xrad, float yrad, float angle);

	void _strcpy(char* target, const char* victim);

			void CopyToComment(const char* source);
};

