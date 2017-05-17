/* Bullet class for Asteroids game clone.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include "Bullet.h"

// default constructor
Bullet::Bullet(const Vector2f& position) {
	// size and position
	setSize(Vector2f(WIDTH, HEIGHT));
	setPosition(position);
	setOrigin(Vector2f(WIDTH/2, HEIGHT/2));

	// format instructions
	setOutlineThickness(1);
	outlineColor = Color::White;
	setOutlineColor(outlineColor);
	setFillColor(Color::Transparent);
}

void Bullet::addVelocity(const Vector2f& velocity) {
	setVelocity(getVelocity() + velocity);
	return;
}

bool Bullet::hit(const Rock& rock) const {
	double xDist = rock.getPosition().x - getPosition().x;
	double yDist = rock.getPosition().y - getPosition().y;
	double radius = rock.getRadius();
	if (xDist*xDist + yDist*yDist < radius*radius) return true;
	return false;
}

void Bullet::setRotation(float angle) {
	Object::setRotation(angle);
	setVelocity(Vector2f(BULLET_SPEED*cos(angle*PI/180), BULLET_SPEED*sin(angle*PI/180)));
	return;
}

int Bullet::timeAlive() const {
	return clock.getElapsedTime().asMilliseconds();
}

void Bullet::setSize(const Vector2f& size) {
	m_size = size;
	update();
}

const Vector2f& Bullet::getSize() const {
	return m_size;
}

std::size_t Bullet::getPointCount() const {
	return 4;
}

Vector2f Bullet::getPoint(std::size_t index) const {
	switch (index) {
		default:
		case 0: return Vector2f(0, 0);
		case 1: return Vector2f(m_size.x, 0);
		case 2: return Vector2f(m_size.x, m_size.y);
		case 3: return Vector2f(0, m_size.y);
	}
}
