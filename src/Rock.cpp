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
	this->level = level;
	radius = 30 * level;
	speed = 500.0/(level*2)/FRAMERATE;
	createShape();
	setPosition(ROCK_SPAWN_POINTS[rand()%4]);
	double direction = (rand()%(2*314))/100.0;
	setVelocity(sf::Vector2f(speed*cos(direction), speed*sin(direction)));

	// format instructions
	setOutlineThickness(1);
	outlineColor = sf::Color::White;
	setOutlineColor(outlineColor);
	setFillColor(sf::Color::Transparent);
}

Rock::Rock(int level, Rock& rock) : Rock(level) {
	setPosition(sf::Vector2f(rock.getPosition().x, rock.getPosition().y));
}

void Rock::createShape() {
	setOrigin(radius, radius);
	for (unsigned int i = 0; i < NUM_POINTS; ++i) {
		double pointRadius = radius + rand()%(12*level)-(6*level);
		double angle = 2.*PI*i/NUM_POINTS;
		double pointX = pointRadius*cos(angle);
		double pointY = pointRadius*sin(angle);
		m_points.push_back(sf::Vector2f(getOrigin().x+pointX, getOrigin().y+pointY));
	}
	return;
}

std::vector<Rock> Rock::split() {
	std::vector<Rock> newRocks;
	if (level > 1) {
		for (unsigned int i = 0; i < NUM_SPLIT_ROCKS; ++i) {
			newRocks.push_back(Rock(level-1, *this));
		}
	}
	return newRocks;
}

// FIXME this collision detection is only a rough estimate and should be made more accurate later.
// It only uses circles as approximations for both the rocks and the ship.
bool Rock::checkShipCollision(const Ship& ship) {
	if (ship.isInGodMode()) return false;
	double diffX = ship.getPosition().x - getPosition().x;
	double diffY = ship.getPosition().y - getPosition().y;
	double diffR = radius + ship.getHeight()/2.0;
	if (diffX*diffX + diffY*diffY < diffR*diffR) return true;
	return false;
}

int Rock::getRadius() const {
	return radius;
}

std::size_t Rock::getPointCount() const {
	return NUM_POINTS;
}

sf::Vector2f Rock::getPoint(std::size_t index) const {
	return m_points[index];
}
