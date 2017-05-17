#include "Object.h"
#include <iostream>
using namespace std;

Object::Object() {}

void Object::setVelocity(const Vector2f& velocity) {
	m_velocity = velocity;
	return;
}

void Object::setAcceleration(const Vector2f& acceleration) {
	m_acceleration = acceleration;
	return;
}

Vector2f Object::getVelocity() const {
	return m_velocity;
}

Vector2f Object::getAcceleration() const {
	return m_acceleration;
}

void Object::update() {
	m_velocity += m_acceleration;
	move(m_velocity);
	checkBounds();
	return;
}

void Object::checkBounds() {
	float xPos = getPosition().x;
	float yPos = getPosition().y;
	if (xPos < 0) setPosition(Vector2f(xPos+WINDOW_X, yPos));
	if (xPos >= WINDOW_X) setPosition(Vector2f(xPos-WINDOW_X, yPos));
	if (yPos < 0) setPosition(Vector2f(xPos, yPos+WINDOW_Y));
	if (yPos >= WINDOW_Y) setPosition(Vector2f(xPos, yPos-WINDOW_Y));
	return;
}

void Object::draw(RenderWindow* window) {
	float xPos = getPosition().x;
	float yPos = getPosition().y;
/*
	if (inGodMode) {
		flash();
	}
*/

	FloatRect box = getGlobalBounds();
	if (box.left <= 0) {
		setPosition(xPos+WINDOW_X, yPos);
		window->draw(*this);
	}
	if (box.left+box.width > WINDOW_X) {
		setPosition(xPos-WINDOW_X, yPos);
		window->draw(*this);
	}
	if (box.top <= 0) {
		setPosition(xPos, yPos+WINDOW_Y);
		window->draw(*this);
	}
	if (box.top+box.height > WINDOW_Y) {
		setPosition(xPos, yPos-WINDOW_Y);
		window->draw(*this);
	}
	if (box.left <= 0 && box.top <= 0) {
		setPosition(xPos+WINDOW_X, yPos+WINDOW_Y);
		window->draw(*this);
	}
	if (box.left+box.width > WINDOW_X && box.top+box.height > WINDOW_Y) {
		setPosition(xPos-WINDOW_X, yPos-WINDOW_Y);
		window->draw(*this);
	}
	if (box.left <= 0 && box.top+box.height > WINDOW_Y) {
		setPosition(xPos+WINDOW_X, yPos-WINDOW_Y);
		window->draw(*this);
	}
	if (box.left+box.width > WINDOW_X && box.top <= 0) {
		setPosition(xPos-WINDOW_X, yPos+WINDOW_Y);
		window->draw(*this);
	}
	setPosition(xPos, yPos);
	window->draw(*this);
	return;
}

void Object::flash() {
	if (godModeTimer.getElapsedTime().asMilliseconds() % (2*flashDuration) < flashDuration) {
		setOutlineColor(Color::Transparent);
	} else {
		setOutlineColor(outlineColor);
	}
	return;
}

void Object::godMode(int duration) {
	godModeTimer.restart();
	godModeDuration = duration;
	inGodMode = true;
	return;
}

void Object::checkGodMode() {
	if (godModeTimer.getElapsedTime().asMilliseconds() >= godModeDuration) {
		inGodMode = false;
	}
	return;
}

bool Object::isInGodMode() const {
	return inGodMode;
}
