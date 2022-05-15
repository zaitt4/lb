#include "Vector.h"

void Vector::fill(int lenth, int begin = 0) {

	for (int i = begin; i < lenth; i++) {

		list[i] = 0;
	}
}


Vector::~Vector() {

	if (list != 0) {
		delete[] list;
	}
}


Vector::Vector() {

	size = 0;
	list = 0;
}


Vector::Vector(int lenth) {

	if (lenth < 0) {

		throw(Exept("Ошибка...Длинна не может быть < 0...\n"));
	}

	size = lenth;

	list = new int[lenth];

	fill(lenth);
}


Vector::Vector(Vector& victim) : Vector() {

	if (victim.size != 0) {

		size = victim.size;

		list = new int[size];

		for (int i = 0; i < size; i++) {

			list[i] = victim.list[i];
		}

	}

}


Vector& Vector::operator()(int newLenth) {

	if (size < 0) {

		throw(Exept("Ошибка изменения, длинна не может быть < 0\n"));
	}

	else if (size == 0) {

		list = new int[newLenth];

		fill(newLenth);
		return *this;
	}

	Vector tmp(*this);

	delete[] list;

	list = new int[newLenth];

	for (int i = 0; i < newLenth; i++) {

		list[i] = tmp.list[i];
	}

	fill(newLenth, size);

	size = newLenth;

	return *this;

}


Vector& Vector::operator++() {
	
	int var;
	std::cin >> var;

	if (std::cin.fail()) {

		throw(Exept("Неверный набор!"));
	}

	if (size == 0) {

		size++;

		list = new int[size];
	}

	else {

		Vector tmp(*this);

		delete[] list;

		list = new int[++size];

		for (int i = 0; i < tmp.size; i++) {		// Сдвиг вправо на 1, что бы освободить 0-й элемент

			list[i + 1] = tmp.list[i];
		}
	}
	
	list[0] = var;

	return *this;
}



Vector& Vector::operator++(int notused) {

	int var;

	std::cin >> var;

	if (std::cin.fail()) {

		throw(Exept("Неверный набор!"));
	}

	if (size == 0) {

		list    = new int[++size];
		list[0] = var;
	}

	else {

		Vector tmp(*this);

		delete[] list;

		list = new int[size + 1];

		for (int i = 0; i < tmp.size; i++) {

			list[i] = tmp.list[i];
		}

		list[size++] = var;
	}

	return *this;
}


int& Vector::operator[](int index) {
	
	if (index < 0 || index >= size) {

		throw(Exept("Ошибка...Выход за пределы массива...\n"));
	}

	return list[index];
}


void Vector::show() {

	if (list == 0) {

		printf("\nВектор пуст...\n");
	}

	else {

		printf("\n");

		for (int i = 0; i < size; i++)

			printf("%d ", list[i]);

		printf("\n");

	}
}
