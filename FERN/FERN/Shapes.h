#pragma once

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>


using namespace std;

sf::RenderWindow window(sf::VideoMode(1800, 980), "fern");

float x;
float y;

void transform(float a, float b, float c, float d, float e, float f) {
	float t1 = x * a + y * b + e;
	float t2 = x * c + y * d + f;
	x = t1;
	y = t2;
}