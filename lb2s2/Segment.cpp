#include "Segment.h"
#include <cmath>
#include <string>
#include <iostream>


float Segment::Get_X_Coordinate() {

	return x;
}


float Segment::Get_Y_Coordinate() {

	return y;
}

float Segment::Get_X2_Coordinate() {

	return x2;
}


float Segment::Get_Y2_Coordinate() {

	return y2;
}


float Segment::Get_SegmentMid_X() {

	return SegmentMid_X;
}


float Segment::Get_SegmentMid_Y() {

	return SegmentMid_Y;
}


float Segment::Get_Segment_Lenth() {

	return SegmentLenth;
}


void Segment::Lenth() {

	SegmentLenth = sqrt(pow(Get_X2_Coordinate() - Get_X_Coordinate(), 2) + pow(Get_Y2_Coordinate() - Get_Y_Coordinate(), 2));
}


void Segment::Set_Segment_Name() {

	printf("Установить имя >> ");
	std::cin.getline(SegmentName, maxlenth);
}


char* Segment::Get_Segment_Name() {

	return SegmentName;
}


void Segment::Mid() {

	SegmentMid_X = (Get_X_Coordinate() + Get_X2_Coordinate()) / 2;
	SegmentMid_Y = (Get_Y_Coordinate() + Get_Y2_Coordinate()) / 2;
}


Segment::Segment(float dot_x, float dot_y, float dot_x2, float dot_y2) {

	x = dot_x; x2 = dot_x2;
	y = dot_y; y2 = dot_y2;
	Lenth();
	Mid();
}
