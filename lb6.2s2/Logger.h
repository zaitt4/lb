#pragma once	
#include <iostream>
#include "Segment.h"
#include <fstream>
#include <ctime>

const int MAX_LOG_LENTH = 1024;
const int MAX_LOG_ITEMS = 128;

class Logger {

	static Logger* pattrn;

	static char** log;

	static bool compare(char* str1, const char* str2);

public:

	static Logger* getSample();

	static void addRecord(Segment& victim, char* logText);

	static void saveLog();

	static void show();

};

