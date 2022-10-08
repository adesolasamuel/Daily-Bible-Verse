//#include <stdio.h>
//#include <time.h>
//#include <string>
//#include <iostream>
//
////Date
//
//int main() {
//
//	struct tm MonthDay;
//	__time64_t aclock;
//	char datebuffer[26];
//	errno_t errNum;
//
//	_time64(&aclock);
//	errNum = _localtime64_s(&MonthDay, &aclock);
//
//	if (MonthDay.tm_mon && MonthDay.tm_mday) {
//		printf("%i", MonthDay.tm_mon);
//		printf("%i", MonthDay.tm_mday);
//
//	}
//
//	//Convert to ASCII Representation
//	errNum = asctime_s(datebuffer, 26, &MonthDay);
//	if (errNum)
//	{
//		printf("Invalid argument to asctime_s.");
//		exit(1);
//	}
//	std::cout << ((std::string)datebuffer).substr(0, 6);
//}