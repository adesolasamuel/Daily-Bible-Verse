#pragma once
#include <fstream>
#include <string>
#include <vector>

class BibleVerse
{

public:
	std::string getDate();
	std::string wrapVerse(std::string verse);
	std::vector <std::string> getverses;
	std::fstream& GotoLine(std::fstream& file, unsigned int num);

};

