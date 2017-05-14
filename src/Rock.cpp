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
//	speed = 600.0/(level*2)/FRAMERATE;
	speed = 300.0/(level*2)/FRAMERATE;
//	if (level == 1) radius *= 2;
	createShape();
	setPos(ROCK_SPAWN_POINTS[rand()%4]);
	setVel(speed*cos(rand()%314/100.0), speed*sin(rand()%314/100.0));
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

// FIXME this collision detection is only a rough estimate and should be made more accurate later.
// It only uses circles as approximations for both the rocks and the ship.
bool Rock::checkShipCollision(const Ship& ship) {
	double diffX = ship.getXPos() - getXPos();
	double diffY = ship.getYPos() - getYPos();
	double diffR = radius + ship.getHeight()/2.0;
	if (diffX*diffX + diffY*diffY < diffR*diffR) return true;
	return false;
}

int Rock::getRadius() const {
	return radius;
}
