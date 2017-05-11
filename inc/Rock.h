/* Rock class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include "Constants.h"
#include "Object.h"
#include "Ship.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Rock : public Object {
private:
	int level;
	int radius;
	static const int NUM_POINTS = 16;

	double speed;

	void createShape();

public:
	Rock(int level);

	void update();

	bool checkShipCollision(const Ship& ship);
	void shipCollision(const Ship& ship);

	vector<Rock> split();
};
