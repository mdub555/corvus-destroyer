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
	double radius;
	static const int NUM_POINTS = 16;

	double speed;

	void createShape();

public:
	Rock(int);
	Rock(int, Rock&);

	bool checkShipCollision(const Ship&);
	int getRadius() const ;

	vector<Rock> split();
};
