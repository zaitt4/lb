#pragma once
#define PI 3.141


int const maxlenth = 256;

enum _Color {

	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Brown,
	LGray,
	DarkGray,
	LBlue,
	LGreen,
	LCyan,
	LRed,
	LMagenta,
	Yellow,
	White

};

class Taper {

	
	//Облегчаторши
	typedef float F;
	typedef void V;


	//Переменши
	F height		  = 0;
	F radius		  = 0;
	F _base_area	= 0;
	F volume		  = 0;

	char Comment[maxlenth] = "N/A";

	//Формульци
	F Volume();
	F BaseArea();

	//Штучки
	void _strcpy(char* target, const char* victim);
	void _this__out(_Color factor);

public:

	//Ко(де-)нструкторши
	Taper();
	Taper(F radius, F height);
	Taper(const Taper &victim);
	~Taper();

	//Сеторши
	V setRadius();
	V setHeight();
	V setComment();
	V setComment(const char* Name);

	//Выводиторши
	V ThrowMeSomeNumbers();

	//Геторши
	F getRadius();
	F getHeight();

};

