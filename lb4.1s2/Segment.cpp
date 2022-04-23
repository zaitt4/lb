#define _CRT_SECURE_NO_WARNIGNS
#define _USE_MATH_DEFINES


#include "Segment.h"
#include <cmath>


void Segment::_strcpy(char* target, const char* victim) {

	for (int i = 0; i < strlen(victim); i++) {

		target[i] = victim[i];
	}
}


Segment::~Segment() {}


Segment::Segment() {

	_strcpy(comment, "Начало координат");
}


Segment::Segment(float x1, float y1, float x2, float y2) {

	this->x1 = x1;		 this->y1 = y1;
	this->x2 = x2;		 this->y2 = y2;

	calculate_middle();
	calculate_lenth();
}


Segment::Segment(Segment& victim) {

	x1 = victim.x1;		 y1 = victim.y1;
	x2 = victim.x2;		 y2 = victim.y2;

	calculate_lenth();
	calculate_middle();
}


void Segment::calculate_lenth() {

	lenth = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void Segment::calculate_middle() {

	x_mid = (x1 + x2) / 2;
	y_mid = (y1 + y2) / 2;
}


void Segment::show_info() {

	printf("1 Точка (%f;%f)\n2 Точка (%f;%f)\n Комментарий: %s\n", x1, y1, x2, y2, comment);
}


std::ostream &operator<<(std::ostream &out, const Segment &victim) {

	out << victim.comment << "\n1 точка: (" << victim.x1 << ";" << victim.y1 << ")"\
		<< "\n2 точка: (" << victim.x2 << ";" << victim.y2 << ")\n";

	return out;
}


std::istream &operator>>(std::istream &inp, Segment &victim) {

	printf("\nКомментарий > ");
	inp >> victim.comment;

	return inp;
}


float &Segment::operator[](int i) {

	switch (i) {

	default:

		return notused = NULL;

	case(1):

		return x1;

	case(2):

		return y1;

	case(3):

		return x2;

	case(4):

		return y2;

	case(5):

		calculate_lenth();
		return lenth;

	case(6):

		calculate_middle();
		return x_mid;

	case(7):

		calculate_middle();
		return y_mid;
	}
}


//Смещение и поворот отрезка
void Segment::operator()(float xrad, float yrad, float angle = 0) {

	x1 += xrad;		y1 += yrad;
	x2 += xrad;		y2 += yrad;
	 
	float vn_x = x2 - x1;		float vn_y = y2 - y1;
	
	float new_vn_x, new_vn_y;

	new_vn_x = vn_x * cos(angle * M_PI / 180) - vn_y * sin(angle * M_PI / 180);
	new_vn_y = vn_x * sin(angle * M_PI / 180) + vn_y * cos(angle * M_PI / 180);

	x2 = new_vn_x + x1;
	
	if (angle < 0)

		y2 = new_vn_y - y1;

	else

		y2 = new_vn_y + y1;
}


void Segment::CopyToComment(const char* source) {

	for (int i = 0; i < strlen(source); i++) {

		comment[i] = source[i];
	}

}

