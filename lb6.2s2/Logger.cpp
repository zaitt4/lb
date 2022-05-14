#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"

bool Logger::compare(char* str1, const char* str2) {

	for (int i = 0; i < strlen(str2); i++) {

		if (str1[i] != str2[i])

			return false;

		return true;
	}
}


Logger* Logger::getSample() {

	if (!pattrn) {

		pattrn = new Logger();

		log = new char* [MAX_LOG_ITEMS];

		for (int i = 0; i < MAX_LOG_ITEMS; i++) {

			log[i] = new char[MAX_LOG_LENTH];
			sprintf(log[i], "");
		}
	}

	return pattrn;
}


void Logger::addRecord(Segment& victim, char* logText) {

	int ind = victim.getNumber() - 1;

	if (log[ind] != 0) {
		
		if (compare(logText, "~delete") == true) {

			sprintf(log[ind], "");
		}

		else {

			sprintf(log[ind], "%s", strcat(log[ind], logText));
		}
	}
}


void Logger::saveLog() {

	std::ofstream logs("log.txt");

	if (!logs) {

		printf("\nЗаписи не сохранены, файл не открылся...");
	}

	else {

		int ind = Segment::getCount();

		char* prefix = new char[24];

		sprintf(prefix, "Segment: %d\n\t", ind);

		logs << prefix;

		for (int i = 0; i < ind; i++) {

			logs << log[i];
		}

		logs.close();
	}
}

/*
void Logger::show() {

	int ind = Segment::getCount();
	for (int i = 0; i < ind; i++) {

		printf("%s\n", Logger::log[i]);
	}
}
*/
