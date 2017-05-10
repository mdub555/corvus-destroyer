#include "Object.h"
#include <iostream>
using namespace std;

Object::Object() {
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	xAcc = 0;
	yAcc = 0;
}

void Object::setPos(double xPos, double yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	updatePosition();
	return;
}

void Object::setXPos(double xPos) {
	this->xPos = xPos;
	updatePosition();
	return;
}

void Object::setYPos(double yPos) {
	this->yPos = yPos;
	updatePosition();
	return;
}

void Object::setXVel(double xVel) {
	this->xVel = xVel;
	return;
}

void Object::setYVel(double yVel) {
	this->yVel = yVel;
	return;
}

void Object::setXAcc(double xAcc) {
	this->xAcc = xAcc;
	return;
}

void Object::setYAcc(double yAcc) {
	this->yAcc = yAcc;
	return;
}

double Object::getXPos() const {
	return xPos;
}

double Object::getYPos() const {
	return yPos;
}

double Object::getXVel() const {
	return xVel;
}

double Object::getYVel() const {
	return yVel;
}

double Object::getXAcc() const {
	return xAcc;
}

double Object::getYAcc() const {
	return yAcc;
}

void Object::update() {
	xVel += xAcc;
	yVel += yAcc;
	xPos += xVel;
	yPos += yVel;
	shape->setPosition(xPos, yPos);
	return;
}

void Object::updatePosition() {
	shape->setPosition(xPos, yPos);
}

void Object::draw(RenderWindow* window) const {
	window->draw(*shape);
	return;
}
