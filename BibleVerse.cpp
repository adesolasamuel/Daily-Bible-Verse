#include "BibleVerse.h"
#include <time.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>

std::string BibleVerse::getDate() {

	//Map Object to hold Months
	std::map <int, std::string> Months;
	Months[0] = "January";
	Months[1] = "February";
	Months[2] = "March";
	Months[3] = "April";
	Months[4] = "May";
	Months[5] = "June";
	Months[6] = "July";
	Months[7] = "August";
	Months[8] = "September";
	Months[9] = "October";
	Months[10] = "November";
	Months[11] = "December";


	// Date Object
	struct tm MonthDay;
	std::stringstream getDate;
	__time64_t aclock;
	char datebuffer[26];
	errno_t errNum;

	_time64(&aclock);
	errNum = _localtime64_s(&MonthDay, &aclock);

	if (MonthDay.tm_mon && MonthDay.tm_mday) {
		
		getDate << Months[MonthDay.tm_mon];
		getDate << " ";
		getDate << MonthDay.tm_mday;

		return getDate.str();

	}
}

std::fstream& BibleVerse::GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

std::string BibleVerse::wrapVerse(std::string verse) {
	std::stringstream ss(verse);
	std::string word;
	int counter = 1;

	while (ss >> word)
	{
		BibleVerse::getverses.push_back(word + " ");
		if (counter % 8 == 0) {
			BibleVerse::getverses.push_back("\n");
		}
		counter++;
	}

	std::stringstream sss;
	for (auto verse : BibleVerse::getverses) {
		sss << verse;
		}

	return sss.str();
}
