#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>


HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONST INT Lenth = 256;
int pass_id = 0;
char None[] = "None";

/* 
		Black         = 0	LightBlue     = 9
        Blue          = 1	LightGreen    = 10
        Green         = 2	LightCyan     = 11
        Cyan          = 3	LightRed      = 12
        Red           = 4	LightMagenta  = 13
        Magenta       = 5	Yellow        = 14
        Brown         = 6	White         = 15 
        LightGray     = 7
        DarkGray      = 8	  
*/


struct Fare {

	char Surname[Lenth];
	int Weight;
	int SitesCount;
	char Flight[Lenth];
};


Fare List_of_Fares[Lenth];


void Color(int Factor);
void ExLogFillBorder();
void ExtendLog(int Factor, int ExtendFactor = 0, int CaseFiveOnlyFactor = 0, std::string OldSurname = None, int OldWeight = 0, int OldSitesCount = 0, std::string OldFlight = None);
void ConcreteMixer();
void SimpleOut();
void demolish();
void append();
void SniffOut(const char* file);
void clog(const char* file);
void Abort();

bool TargetExist(int Target);

int MainMenu();
int rangeDetect(char* var, char* anotherVar);
int Tunning(const char* file);

char Exitbl();


int main() {

	ExLogFillBorder();
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	pass_id = Tunning("log.dat");
	Color(15);

	while (true) {

		switch (MainMenu()) {

		case 0:

			char ExitFactor;
			ExitFactor = Exitbl();

			if (toupper(ExitFactor) == 'Y') {

				return 0;
			}

			break;


		case 1:

			SniffOut("log.dat");
			break;

		case 2:

			append();
			break;

		case 3:

			demolish();
			break;

		case 4:

			clog("log.dat");
			break;

		case 5:

			ConcreteMixer();
			break;

		case 6:

			Abort();
			break;
		};

	}

}


void Abort() {

	if (pass_id < 1) {

		Color(4);
		printf("Список порожен");

		Color(15);
	}

	else {

		SimpleOut();
		printf("\n\nКого нужно абортировать? >> ");

		int Factor, id;

		std::cin >> id;

		while (id < 0 || id > pass_id) {

			Color(4);
			printf("\nНЕВЕРНЫЙ НАБОРТ");

			Color(15);
			printf(" [1,%d] >> ", pass_id);
		}

		id -= 1;

		printf("\nПо какому критерию абортировать %s?\n\n", List_of_Fares[id].Surname);


		printf("По Фамильице\t\t ~ 1 ~\n");
		printf("По весу клади\t\t ~ 2 ~\n");
		printf("По койке\t\t ~ 3 ~\n");
		printf("По рейсу\t\t ~ 4 ~\n\n");

		printf(">> ");

		std::cin >> Factor;

		while (Factor < 0 || Factor > 4) {

			Color(4);
			printf("\nНЕВЕРНЫЙ НАБОРТ");

			Color(15);
			printf(" [1,4] >> ");
		}

		std::string Old_Surname = List_of_Fares[id].Surname;

		int Old_Weight = List_of_Fares[id].Weight;
		int Old_Sites_Count = List_of_Fares[id].SitesCount;

		std::string Old_Flight = List_of_Fares[id].Flight;

		switch (Factor) {

		case 1:

			std::cin.ignore();
			printf("Новая Фамильица для %s >> ", List_of_Fares[id].Surname);

			std::cin.getline(List_of_Fares[id].Surname, Lenth);

			break;

		case 2:

			printf("Новый брутто %s >> ", List_of_Fares[id].Surname);
			std::cin >> List_of_Fares[id].Weight;

			break;

		case 3:


			printf("Новое количетсво мест для %s>> ", List_of_Fares[id].Surname);
			std::cin >> List_of_Fares[id].SitesCount;

			break;

		case 4:

			std::cin.ignore();
			printf("Новый рейс для %s >> ", List_of_Fares[id].Surname);
			std::cin.getline(List_of_Fares[id].Flight, Lenth);

			break;
		}

		clog("log.dat");
		ExtendLog(5, Factor, id, Old_Surname, Old_Weight, Old_Sites_Count, Old_Flight);

	}
}


void Color(int Factor) {

	SetConsoleTextAttribute(handle, Factor);
}


void ExLogFillBorder() {

	std::ofstream fLog("Actions.txt", std::ios::app);

	fLog << "\n";

	for (int i = 0; i < 60; i++) {

		fLog << "~";
	}

	fLog << "\n\n";

	fLog.close();
}


void ExtendLog(int Factor, int ExtendFactor, int CaseFiveOnlyFactor, std::string OldSurname, int OldWeight, int OldSitesCount, std::string OldFlight) {

	std::ofstream fLog("Actions.txt", std::ios::app);

	if (!fLog) {

		Color(4);
		printf("Файл не отворился...");

		Color(15);
	}

	else {

		switch (Factor) {

		case 1:

			fLog << "Добавление: " << List_of_Fares[pass_id].Surname << "\n";
			break;

		case 2:

			fLog << "Удаление: " << List_of_Fares[ExtendFactor].Surname << "\n";
			break;

		case 3:

			fLog << "Сохранение.\n";

			break;

		case 4:

			fLog << "Сортировка по ";

			switch (ExtendFactor) {

			case 1:

				fLog << "фамильицам.\n";
				break;

			case 2:

				fLog << "весу клажи.\n";
				break;

			case 3:

				fLog << "койкам.\n";
				break;

			case 4:

				fLog << "рейсам.\n";
				break;
			}

		case 5:

			fLog << "Изменение ";

			switch (ExtendFactor) {

			case 1:
				 
				fLog << "Фамильици " << OldSurname << " на новую: " << List_of_Fares[CaseFiveOnlyFactor].Surname << "\n";
				break;

			case 2:

				fLog << "Веса клади " << List_of_Fares[CaseFiveOnlyFactor].Surname << ": " << OldWeight <<"; на новый: " << List_of_Fares[CaseFiveOnlyFactor].Weight << "\n";
				break;

			case 3:

				fLog << "Коек " << List_of_Fares[CaseFiveOnlyFactor].Surname << ": " << OldSitesCount << "; на новый: " << List_of_Fares[CaseFiveOnlyFactor].SitesCount << "\n";
				break;

			case 4:

				fLog << "Рейса " << List_of_Fares[CaseFiveOnlyFactor].Surname << ": " << OldFlight << "; на новый: " << List_of_Fares[CaseFiveOnlyFactor].Flight << "\n";
				break;
			}

		}

		fLog.close();
	}

	

}


int rangeDetect(char* var, char* anotherVar) {

	int range;

	if (strlen(var) > strlen(anotherVar)) {

		range = strlen(anotherVar);
	}

	else if (strlen(var) < strlen(anotherVar)) {

		range = strlen(var);
	}

	else {

		range = strlen(var);
	}

	return range;
}


void ConcreteMixer() {

	Color(10);
	printf("\n\t\nПо каким нормам вести сортировку?\n");

	Color(15);

	printf("Фамильица(По азбуке)\t ~ 1 ~\n");
	printf("Вес клади\t\t ~ 2 ~\n");
	printf("Койка\t\t\t ~ 3 ~\n");
	printf("Рейс\t\t\t ~ 4 ~\n");

	printf(">> ");
	int Factor = -1;

	std::cin >> Factor;

	while (Factor < 0 || Factor > 4) {

		Color(4);
		printf("НЕВЕРНЫЙ ВВОД");

		Color(15);
		printf(" >> ");
		std::cin >> Factor;
	}
	
	switch (Factor) {

	case 1:

		for (int factor = 0; factor < pass_id; factor++) {

			for (int i = 0; i < pass_id - factor - 1; i++) {

				char* var = List_of_Fares[i].Surname;
				char* nextVar = List_of_Fares[i + 1].Surname;

				int range;

				range = rangeDetect(var, nextVar);

				bool sortFactor = false;

				for (int j = 0; j < range; j++) {

					if (var[j] == nextVar[j]) {

						continue;
					}

					if (var[j] > nextVar[j]) {

						sortFactor = true;
						break;
					}

				}

				if (sortFactor = true) {

					Fare tempFare = List_of_Fares[i];

					List_of_Fares[i] = List_of_Fares[i + 1];
					List_of_Fares[i + 1] = tempFare;
				}

			}

		}

		Color(10);
		printf("\tСортировка фамильиц окончена здравием...\n");

		Color(15);

		break;

	case 2:

		for (int factor = 0; factor < pass_id; factor++) {

			for (int i = 0; i < pass_id - factor - 1; i++) {

				int var = List_of_Fares[i].Weight;
				int nextVar = List_of_Fares[i + 1].Weight;

				if (var < nextVar) {

					Fare tempFare = List_of_Fares[i];

					List_of_Fares[i] = List_of_Fares[i + 1];
					List_of_Fares[i + 1] = tempFare;
				}

			}

		}

		Color(10);
		printf("\tСортировка по весу клади завершилась с успехом...\n");

		Color(15);
		break;

	case 3:

		for (int factor = 0; factor < pass_id; factor++) {

			for (int i = 0; i < pass_id - factor - 1; i++) {

				int var = List_of_Fares[i].SitesCount;
				int nextVar = List_of_Fares[i + 1].SitesCount;

				if (var < nextVar) {

					Fare tempFare = List_of_Fares[i];

					List_of_Fares[i] = List_of_Fares[i + 1];
					List_of_Fares[i + 1] = tempFare;
				}

			}

		}

		Color(10);
		printf("\tСортировка местам прошла удачно...\n");

		Color(15);

		break;

	case 4:

		for (int factor = 0; factor < pass_id; factor++) {

			for (int i = 0; i < pass_id - factor - 1; i++) {

				char* var = List_of_Fares[i].Surname;
				char* nextVar = List_of_Fares[i + 1].Surname;

				int range;

				range = rangeDetect(var, nextVar);

				bool sortFactor = false;

				for (int j = 0; j < range; j++) {

					if (var[j] == nextVar[j]) {

						continue;
					}

					if (var[j] > nextVar[j]) {

						sortFactor = true;
						break;
					}

				}

				if (sortFactor = true) {

					Fare tempFare = List_of_Fares[i];

					List_of_Fares[i] = List_of_Fares[i + 1];
					List_of_Fares[i + 1] = tempFare;
				}

			}

		}

		Color(10);
		printf("\tСортировка по рейсам передаёт привет...\n");

		Color(15);;

		break;
	}

	clog("log.dat");

	ExtendLog(4, Factor);
}


bool TargetExist(int Target) {

	for (int i = 0; i < pass_id; i++) {

		if ((i + 1) == Target) {

			return true;
		}
	}

	return false;
}


void demolish() {

	printf("\nВведите номер который нужно соскрести\n>> ");

	int Target;
	std::cin >> Target;


	if (pass_id < 1) {

		Color(4);
		printf("\nСписок порожен\n");

		Color(15);
	}

	else if (TargetExist(Target) == false) {

		Color(4);
		printf("\n\tНесть указанного номера");

		Color(15);
	}

	else {

		Target -= 1;
		ExtendLog(2, Target);

		for (int i = Target; i < pass_id; i++) {

			List_of_Fares[i] = List_of_Fares[i + 1];
		}

		pass_id--;

		SimpleOut();
	}

}


void append() {

	Color(10);
	printf("\n\tСедок номер %i:\n\n", pass_id + 1);

	Color(15);
	
	std::cin.ignore();
	printf("Фамильица >> ");
	std::cin.getline(List_of_Fares[pass_id].Surname, Lenth);

	printf("Брутто >> ");
	std::cin >> List_of_Fares[pass_id].Weight;

	std::cin.ignore();
	printf("Количетсво мест >> ");
	std::cin >> List_of_Fares[pass_id].SitesCount;

	std::cin.ignore();
	printf("Рейс >> ");
	std::cin.getline(List_of_Fares[pass_id].Flight, Lenth);

	Color(10);
	printf("\n\tУспешно добавлено...\n");

	Color(15);
	
	ExtendLog(1);
	pass_id++;

	SimpleOut();
}


int Tunning(const char* file) {

	std::ifstream File;
	File.open(file, std::ios::binary);

	if (!File) {

		return -1;
	}

	while (true) {

		Fare passenger;
		File.read((char*)&passenger, sizeof(passenger));

		if (File.eof()) {

			break;
		}

		List_of_Fares[pass_id] = passenger;
		pass_id++;
	}

	File.close();
	return pass_id;
}


void SimpleOut() {

	printf("\n");

	for (int i = 0; i < pass_id; i++) {

		printf("%d.\t%s\t\t:", i + 1, List_of_Fares[i].Surname);

		if (List_of_Fares[i].Weight > 23 && List_of_Fares[i].Weight < 32) {

			printf("\tВес поклажи: ");

			Color(14);
			printf("%d", List_of_Fares[i].Weight);

			Color(15);
			printf(";\t\t");
		}

		else if (List_of_Fares[i].Weight < 23 && List_of_Fares[i].Weight > 0) {

			printf("\tВес поклажи: ");

			Color(10);
			printf("%d", List_of_Fares[i].Weight);

			Color(15);
			printf(";\t\t");
		}

		else if (List_of_Fares[i].Weight > 32) {

			printf("\tВес поклажи: ");

			Color(4);
			printf("%d", List_of_Fares[i].Weight);

			Color(15);
			printf(";\t\t");
		}

		else {

			printf("\tВес поклажи: %d;\t\t", List_of_Fares[i].Weight);

		}

		printf("\tКоек: %d;\t\tРейс: %s\n", List_of_Fares[i].SitesCount, List_of_Fares[i].Flight);

	}

}


void SniffOut(const char* file) {

	std::ifstream File;
	File.open(file, std::ios::binary);

	if (!File) {

		Color(4);
		printf("Файл не отворился\n");
	}

	if (pass_id < 1) {

		Color(4);
		printf("\nСписок порожен\n\n");

	}

	Color(15);

	int pass_id = 0;

	while (true) {

		Fare passenger;
		File.read((char*)&passenger, sizeof(passenger));
		
		if (File.eof()) {

			break;
		}

		List_of_Fares[pass_id] = passenger;
		pass_id++;
	}

	SimpleOut();

	File.close();
}


void clog(const char* file) {

	std::ofstream File;
	File.open(file, std::ios::binary);

	if (!File) {

		Color(4);
		printf("Файл не отворился...\n");

		Color(15);
	}

	File.write((char*)&List_of_Fares, sizeof(Fare) * pass_id);

	File.close();

	Color(10);
	printf("\tУспешно обновлено...");

	Color(15);

	SimpleOut();

	ExtendLog(3);
}


char Exitbl() {

	bool factor = true;

	char decision;
	printf("Серьёзно? [Y/N] >> ");

	std::cin >> decision;

	while (factor) {

		if (toupper(decision) == 'Y' || toupper(decision) == 'N') {

			factor = false;
			continue;
		}

		Color(4);
		printf("НЕВЕРНЫЙ НАБОР ");

		Color(15);
		printf("[Y/N] >> ");
		std::cin >> decision;

	}

	return decision;
}


int MainMenu() {

	int factor = -1;

	printf("\nПронюхать из файла\t ~ 1 ~\n");
	printf("Заключить\t\t ~ 2 ~\n");
	printf("Вылучить\t\t ~ 3 ~\n");
	printf("Обновить файл\t\t ~ 4 ~\n");
	printf("Сортировка\t\t ~ 5 ~\n");
	printf("Переродить\t\t ~ 6 ~\n");
	printf("Отчалить\t\t ~ 0 ~\n");

	printf("\n>> ");
	std::cin >> factor;

	while (factor < 0 || factor > 6) {

		
		Color(4);
		printf("НЕВЕРНЫЙ НАБОР ");

		Color(15);
		printf("[0,6] >> ");
		std::cin >> factor;
		
	}

	Color(15);
	return factor;
}
