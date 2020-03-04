#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "windows.h"
#include "Shapes.h"

using namespace std;

sf::Vector2i mousePos = sf::Mouse::getPosition(window);

float p[4] = {1,7,7,85};
int radius = 1;
int scale = 120;
int xi = 1400;
int yi = 500;

sf::CircleShape t;
sf::CircleShape fix;

//vector<int> cd;

int main() {
	//-------------------------
	t.setFillColor(sf::Color(0, 255, 0));
	t.setRadius(radius);
	t.setPosition(x, y);
	fix.setFillColor(sf::Color(0, 255, 0));
	fix.setRadius(radius);
	fix.setPosition(x, y);
	//-------------------------
	while (window.isOpen()) {
		//pause
		Sleep(0);

		//clear window and get mousepos
		//window.clear(sf::Color(255, 255, 255));
		mousePos = sf::Mouse::getPosition(window);

		//check for closing window
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		//-------------------------

		fix.setPosition(scale * (-y) + xi, scale * x + yi);
		window.draw(fix);

		int k = rand() % 100 + 1;
		if (k <= p[0]) {
			transform(0, 0, 0, 0.16, 0, 0);
		} else if (k <= p[1] + p[0]) {
			transform(-0.15, 0.28, 0.26, 0.24, 0, 0.44);
		} else if (k <= p[2] + p[1] + p[0]) {
			transform(0.20, -0.26, 0.23, 0.22, 0, 1.60);
		}else {
			transform(0.85, 0.04, -0.04, 0.85, 0, 1.6);
		}

		t.setPosition(scale * (-y) + xi, scale * x + yi);
		window.draw(t);
		//-------------------------
		//display 
		window.display();
	}
	return 0;
}
