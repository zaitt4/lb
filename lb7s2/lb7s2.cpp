#include "Vector.h"

int main() {

	setlocale(LC_ALL, "ru");

	try {

		Vector alpha;

		for (int i = 0; i < 6; i++) {

			alpha++;
		}

		alpha.show();

		alpha(3);

		alpha.show();

		for (int i = 2; i < 5; i++) {

			++alpha;
		}
		
		alpha.show();
        
        Vector betta(-2); // Ошибка размера
		alpha[11];        // Ошибка доступа по адресу (выход за рамки массива)
                          // Другие ошибки реализовано во вводе с помощью оператора ++

	}

	catch (Exept& victim) {

		victim.info();
	}
}
