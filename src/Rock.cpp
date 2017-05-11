/* Rock class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Rock.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>

// default constructor
Rock::Rock(int level) {
//	srand(time(NULL));
	this->level = level;
	radius = 30 * level;
//	if (level == 1) radius *= 2;
	createShape();
	setPos(ROCK_SPAWN_POINTS[rand()%4]);
}

Rock::Rock(int level, Rock& rock) : Rock(level) {
	setPos(rock.getXPos(), rock.getYPos());
}

void Rock::createShape() {
	ConvexShape tmpshape;
	tmpshape.setOrigin(radius, radius);
	tmpshape.setPointCount(NUM_POINTS);
	tmpshape.setFillColor(Color::Transparent);
	tmpshape.setOutlineColor(Color::White);
	tmpshape.setOutlineThickness(1);
	for (int i = 0; i < NUM_POINTS; ++i) {
		double pointRadius = radius + rand()%(5*level*level)-(3*level*level);
		double angle = 2.*PI*i/NUM_POINTS;
		double pointX = pointRadius*cos(angle);
		double pointY = pointRadius*sin(angle);
		Vector2f point(tmpshape.getOrigin().x + pointX, tmpshape.getOrigin().y + pointY);
		tmpshape.setPoint(i, point);
	}
	shape = new ConvexShape(tmpshape);
	return;
}

vector<Rock> Rock::split() {
	vector<Rock> newRocks;
	if (level > 1) {
		newRocks.push_back(Rock(level-1, *this));
		newRocks.push_back(Rock(level-1, *this));
	}
	return newRocks;
}

// updates the position of the Rock based on the x and y velocities
void Rock::update() {
	return;
}

bool Rock::checkShipCollision(const Ship& ship) {
	return false;
}

// changes the velocity of the Rock if it hits the ship. the velocity change is based on the
// distance from the center of the ship, and uses a sine and cosine function as the parameters
// of that change
void Rock::shipCollision(const Ship& ship) {
	return;
}

int Rock::getRadius() const {
	return radius;
}
