#pragma once

class Segment {

private:

	static const int maxlenth = 256;

	char SegmentName[maxlenth];

	float x; float x2;
	float y; float y2;

	float SegmentLenth;
	float SegmentMid_X;
	float SegmentMid_Y;

public:

	Segment(float dot_x, float dot_y, float dot_x2, float dot_y2);

	float Get_X_Coordinate(); float Get_X2_Coordinate();
	float Get_Y_Coordinate(); float Get_Y2_Coordinate();
	float Get_Segment_Lenth();
	float Get_SegmentMid_X(); float Get_SegmentMid_Y();


	char* Get_Segment_Name();


	void Set_Segment_Name();
	void Lenth();
	void Mid();


};

