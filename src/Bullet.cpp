/* Bullet class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Bullet.h"

// default constructor
Bullet::Bullet(double direction) {
}

void Bullet::createShape() {
	return;
}

void Bullet::update() {
	return;
}

// move the position of the Bullet
void Bullet::move(int x, int y) {
	bullet.move(x, y);
	return;
}

// sets the position of the Bullet
void Bullet::setPos(int x, int y) {
	bullet.setPosition(x, y);
	return;
}

// returns the x-position of the Bullet
double Bullet::getXPos() const {
	return bullet.getPosition().x;
}

// returns the y-position of the Bullet
double Bullet::getYPos() const {
	return bullet.getPosition().y;
}

// returns the width of the Bullet
double Bullet::getLength() const {
	return LENGTH;
}

bool Bullet::hit(const Rock& rock) const {
	return false;
}

void Bullet::draw(RenderWindow& window) const {
	return;
}
