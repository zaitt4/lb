#include <iostream>
#include "Segment.h"
#include <windows.h>

int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Segment Line(1, 4, 3, 8);

	Line.Set_Segment_Name();
	printf("\nОтрезок %s\n", Line.Get_Segment_Name());
	printf("\n1 точка (%f,%f)\n", Line.Get_X_Coordinate(), Line.Get_Y_Coordinate());
	printf("\n2 точка (%f,%f)\n", Line.Get_X2_Coordinate(), Line.Get_Y2_Coordinate());
	printf("\nСередина отрезка %s (%f,%f)\n", Line.Get_Segment_Name(), Line.Get_SegmentMid_X(), Line.Get_SegmentMid_Y());

	Line.Lenth();
	printf("\nДлина: %f\n", Line.Get_Segment_Lenth());
}