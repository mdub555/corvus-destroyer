/* Bullet class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Bullet.h"

// default constructor
Bullet::Bullet() {
	createShape();
}

void Bullet::createShape() {
	RectangleShape tmpshape(Vector2f(WIDTH, HEIGHT));
	tmpshape.setFillColor(Color::Transparent);
	tmpshape.setOutlineColor(Color::White);
	tmpshape.setOutlineThickness(1);
	tmpshape.setOrigin(WIDTH/2, HEIGHT/2);
	shape = new RectangleShape(tmpshape);
	return;
}

bool Bullet::hit(const Rock& rock) const {
	double xDist = rock.getXPos() - getXPos();
	double yDist = rock.getYPos() - getYPos();
	double radius = rock.getRadius();
	if (xDist*xDist + yDist*yDist < radius*radius) return true;
	return false;
}

void Bullet::setRotation(double angle) {
	Object::setRotation(angle);
	setXVel(BULLET_SPEED*cos(getRotation()*PI/180));
	setYVel(BULLET_SPEED*sin(getRotation()*PI/180));
	return;
}
