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
#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Rock : public Object {
private:
	static const unsigned int NUM_POINTS = 16;
	int    level;
	double radius;
	double speed;

	vector<Vector2f> m_points;

	void createShape();

public:
	Rock(int);
	Rock(int, Rock&);
	virtual std::size_t getPointCount() const;
	virtual Vector2f getPoint(std::size_t index) const;

	bool checkShipCollision(const Ship&);
	int getRadius() const ;

	vector<Rock> split();
};
