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
	radius = 10 * level * level;
	createShape();
	rock.setPosition(WINDOW_X/2, WINDOW_Y/2);
}

void Rock::createShape() {
	rock.setOrigin(radius, radius);
	rock.setPointCount(NUM_POINTS);
	rock.setFillColor(Color::Transparent);
	rock.setOutlineColor(Color::White);
	rock.setOutlineThickness(1);
	for (int i = 0; i < NUM_POINTS; ++i) {
		double pointRadius = radius + rand()%(5*level*level)-(3*level*level);
		double angle = 2.*PI*i/NUM_POINTS;
		double pointX = pointRadius*cos(angle);
		double pointY = pointRadius*sin(angle);
		Vector2f point(rock.getOrigin().x + pointX, rock.getOrigin().y + pointY);
		rock.setPoint(i, point);
	}
	return;
}

vector<Rock> Rock::split() {
	vector<Rock> rocks;
	if (level > 1) {
		rocks.push_back(Rock(level-1));
		rocks.push_back(Rock(level-1));
	}
	return rocks;
}

// returns the x-position of the Rock
double Rock::getX() const {
	return rock.getPosition().x;
}

// returns the y-position of the Rock
double Rock::getY() const {
	return rock.getPosition().y;
}

// returns the x-velocity of the Rock
double Rock::getXVel() const {
	return xVel;
}

// returns the y-velocity of the Rock
double Rock::getYVel() const {
	return yVel;
}

// sets the position of the Rock
void Rock::setPosition(double x, double y) {
	rock.setPosition(x, y);
	return;
}

// sets the velocity of the Rock
void Rock::setVelocity(double x, double y) {
	xVel = x;
	yVel = y;
	return;
}

void Rock::setSpeed(double speed) {
	return;
}

// updates the position of the Rock based on the x and y velocities
void Rock::update() {
	return;
}

bool Rock::checkWallCollision() {
	return false;
}

// changes the velocity of the Rock if it hits the walls of the screen
void Rock::wallCollision() {
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

void Rock::draw(RenderWindow& window) const {
	window.draw(rock);
	return;
}
