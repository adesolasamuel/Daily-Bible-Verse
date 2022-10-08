// Daily Bible Verse.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This project will create a text file called Bible Verse Today.txt on the desktop and put a random bible verse there
// whenever a computer was started. The application will run on startup.


#include <string>
#include <cstdlib>
#include <string>
#include <limits>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "BibleVerse.h"


BibleVerse bibleapp;


int main()
{
	
	//Creating and SFML Window
	sf::RenderWindow window(sf::VideoMode(900, 500), "Daily Bible Verse", sf::Style::Close);
	window.setFramerateLimit(60);

	//Fonts 
	sf::Font dateFont;
		if (!dateFont.loadFromFile("YellowDisplayRegular.ttf")) {
			throw std::string("Could Not Load Date Font");
		}

	sf::Font verseFont;
		if (!verseFont.loadFromFile("DelmonDelicate.ttf")) {
			throw std::string("Could Not Load Verse Font");
		}

	//Nav bar
		sf::RectangleShape navline(sf::Vector2f(window.getSize().x, 2.f));
		navline.setPosition(0.f, 15.f);
		navline.setFillColor(sf::Color(128, 128, 128));
		

	//Creating SFML Text objects

	sf::Text dateText;
	dateText.setFont(dateFont);
	dateText.setFillColor(sf::Color::Black);
	dateText.setCharacterSize(28);
	dateText.setPosition(400.f, 100.f);
	dateText.setString(bibleapp.getDate());

	sf::Text verseText;
	verseText.setFont(verseFont);
	verseText.setFillColor(sf::Color::Black);
	verseText.setCharacterSize(32);
	verseText.setPosition(70.f, 200.f);


	//ofstream object for reading the text file
	bool isSameDay = false;
	std::fstream readBible, thisDay, thisnewDay, dailyVerse;
	std::string verse, daybuffer, dailyversebuffer;
	readBible.open("NewTestament.txt", std::ios::in);

	thisDay.open("thisday.txt", std::ios::in | std::ios::out);
	if (thisDay.is_open()) {
		std::getline(thisDay, daybuffer);

		if (bibleapp.getDate() != daybuffer) {
			isSameDay = false;
			thisnewDay.open("thisday.txt", std::ios::in | std::ios::out | std::ios::trunc);
			if (thisnewDay.is_open()) {
				thisnewDay << bibleapp.getDate();
				thisnewDay.close();
			}
		}
		else {
			isSameDay = true;
		}
			//std::cout << daybuffer;
			//std::cout << bibleapp.getDate();
			thisDay.close();
	}

	//Reading Bible and Writing Bible
	//Main Engine here

	if (readBible.is_open()) {
			srand(time(NULL));
			if (isSameDay == false) {
				bibleapp.GotoLine(readBible, 1 + rand() % 7957);
				std::getline(readBible, verse);
				dailyVerse.open("bibleverse.txt", std::ios::in | std::ios::out | std::ios::trunc);
				if (dailyVerse.is_open())
				{
					dailyVerse << verse;	
					//std::getline(dailyVerse, verse);
				}
				
				
			}
			else {
				dailyVerse.open("bibleverse.txt", std::ios::in | std::ios::out);
				std::getline(dailyVerse, verse);
				dailyVerse.close();
			}

			

			std::string formattedString = bibleapp.wrapVerse(verse);

			verseText.setString(formattedString);
		readBible.close();
	}
	else {
		//std::cout << "Could not read Bible Verses" << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed) {
				window.close();
			}
		}

		//Update

		//Draw
		window.clear(sf::Color::White);
		window.draw(navline);
		window.draw(dateText);
		window.draw(verseText);


		//Display
		window.display();

	}

	
	return 0;

	
}


