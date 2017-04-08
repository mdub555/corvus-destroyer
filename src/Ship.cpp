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
	ship.setPosition(WINDOW_X/2, WINDOW_Y/2);
}

void Ship::createShape() {
	ship.setFillColor(Color::Transparent);
	ship.setOutlineColor(Color::White);
	ship.setOutlineThickness(1);
	ship.setPointCount(3);
	ship.setPoint(0, Vector2f(HEIGHT, WIDTH/2));
	ship.setPoint(1, Vector2f(0, WIDTH));
	ship.setPoint(2, Vector2f(0, 0));
	ship.setOrigin(HEIGHT/3, WIDTH/2);
	ship.rotate(-90);
	return;
}

void Ship::update() {
	ship.rotate(rotation*ROTATION_SPEED);
	accelerate();
	ship.move(xVel, yVel);
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
		xVel += ACCELERATION*cos(ship.getRotation()*PI/180);
		yVel += ACCELERATION*sin(ship.getRotation()*PI/180);
	}
	return;
}

// returns the y-position of the Ship
double Ship::getYPos() const {
	return ship.getPosition().y;
}

// returns the y-position of the Ship
double Ship::getXPos() const {
	return ship.getPosition().x;
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

void Ship::draw(RenderWindow* window) const {
	window->draw(ship);
	return;
}
