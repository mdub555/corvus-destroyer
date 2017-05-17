/* Ship class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Ship.h"
#include <cmath>

// default constructor. the Ship is made of a rectangle and two circles.
Ship::Ship(const Vector2f& position) {
	rotation = 0;
	accel = false;
	setPosition(position);
	inGodMode = false;

	setOrigin(Vector2f(HEIGHT/3, WIDTH/2));

	setOutlineThickness(1);
	outlineColor = Color::White;
	setOutlineColor(outlineColor);
	setFillColor(Color::Transparent);
}

void Ship::update() {
	rotate(rotation*ROTATION_SPEED);
	accelerate();
	Object::update();
	validateSpeed();
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
		setAcceleration(Vector2f(ACCELERATION*cos(getRotation()*PI/180), ACCELERATION*sin(getRotation()*PI/180)));
	} else {
		setAcceleration(Vector2f(0, 0));
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

void Ship::validateSpeed() {
	double xVel = getVelocity().x;
	double yVel = getVelocity().y;
	if (xVel > MAX_VELOCITY)  setVelocity(Vector2f(xVel,  MAX_VELOCITY));
	if (xVel < -MAX_VELOCITY) setVelocity(Vector2f(xVel, -MAX_VELOCITY));
	if (yVel > MAX_VELOCITY)  setVelocity(Vector2f(yVel,  MAX_VELOCITY));
	if (yVel < -MAX_VELOCITY) setVelocity(Vector2f(yVel, -MAX_VELOCITY));
	return;
}

void Ship::destroyAnimation() {
	return;
}

void Ship::respawnInvinsible() {
	respawn();
	godMode(1500);
	return;
}

void Ship::respawn() {
	setPosition(Vector2f(WINDOW_X/2, WINDOW_Y/2));
	setRotation(-90);
	setVelocity(Vector2f(0, 0));
	return;
}

std::size_t Ship::getPointCount() const {
	return 3;
}

Vector2f Ship::getPoint(std::size_t index) const {
	switch (index) {
		default:
		case 0: return Vector2f(HEIGHT, WIDTH/2);
		case 1: return Vector2f(0, WIDTH);
		case 2: return Vector2f(0, 0);
	}
}
