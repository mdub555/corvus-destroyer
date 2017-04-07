/* Ship class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Ship.h"

// default constructor. the Ship is made of a rectangle and two circles.
Ship::Ship() {
}

void Ship::createShape() {
	return;
}

// returns the y-position of the Ship
double Ship::getYPos() const {
	return yPos;
}

// returns the y-position of the Ship
double Ship::getXPos() const {
	return xPos;
}

// returns the height of the Ship
double Ship::getHeight() const {
	return height;
}

// returns the width of the Ship
double Ship::getWidth() const {
	return width;
}

// moves each section of the Ship based on the input parameter. There are limits to the possible
// locations of the Ship, such that the Ship stops at the edges of the screen.
void Ship::move(double x, double y) {
	return;
}

void Ship::draw(RenderWindow* window) const {
	return;
}
