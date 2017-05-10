/* Ship class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Ship.h"
#include <cmath>

// default constructor. the Ship is made of a rectangle and two circles.
Ship::Ship() {
	rotation = 0;
	accel = false;
	createShape();
	setPos(WINDOW_X/2, WINDOW_Y/2);
}

void Ship::createShape() {
	ConvexShape tmpshape;
	tmpshape.setFillColor(Color::Transparent);
	tmpshape.setOutlineColor(Color::White);
	tmpshape.setOutlineThickness(1);
	tmpshape.setPointCount(3);
	tmpshape.setPoint(0, Vector2f(HEIGHT, WIDTH/2));
	tmpshape.setPoint(1, Vector2f(0, WIDTH));
	tmpshape.setPoint(2, Vector2f(0, 0));
	tmpshape.setOrigin(HEIGHT/3, WIDTH/2);
	tmpshape.rotate(-90);
	shape = new ConvexShape(tmpshape);
	return;
}

void Ship::update() {
	shape->rotate(rotation*ROTATION_SPEED);
	accelerate();
	Object::update();
	return;
}

void Ship::setRotate(int direction) {
	rotation = direction;
	return;
}

void Ship::stopAccel() {
	accel = false;
}

void Ship::startAccel() {
	accel = true;
}

void Ship::accelerate() {
	if (accel) {
		setXAcc(ACCELERATION*cos(shape->getRotation()*PI/180));
		setYAcc(ACCELERATION*sin(shape->getRotation()*PI/180));
	} else {
		setXAcc(0);
		setYAcc(0);
	}
	return;
}

// returns the height of the Ship
double Ship::getHeight() const {
	return HEIGHT;
}

// returns the width of the Ship
double Ship::getWidth() const {
	return WIDTH;
}

// moves each section of the Ship based on the input parameter. There are limits to the possible
// locations of the Ship, such that the Ship stops at the edges of the screen.
void Ship::move(double x, double y) {
	return;
}
