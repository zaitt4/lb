#pragma once
#include <iostream>

class Exept {

	const char* msg[64];
	
public:

	Exept(const char msg[64]) {

		*this->msg = msg;
	}

	void info() {

		printf("%s", *msg);
	}
};


class Vector {

	int size;
	int* list;

	void fill(int lenth, int begin);

public:
	
	~Vector();
	Vector();
	Vector(int lenth);
	Vector(Vector& victim);

			Vector& operator()(int newLenth);
			Vector& operator++();
	Vector& operator++(int notused);
	int& operator[](int index);

	void show();

};

