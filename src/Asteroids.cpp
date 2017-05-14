/* Main file for Asteroids game clone. This is a very rudementary start of the clone and will be
 * expanded upon soon in the future. All it does right now it make a rock and allow the rock to be
 * split when the space bar is pressed.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Asteroids.h"

// loads the font and then plays the game
int main() {
	srand(time(NULL));

	Asteroids game;
	game.setFPS(FRAMERATE);

	while (game.isOpen()) {
		game.draw();
		game.checkEvent();
		game.applyEvents();
	}
	return 0;
}

Asteroids::Asteroids() {
	currentState.push(MAIN_MENU);
	window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), "Bullet Breaker!");
	level = -1;
	lives = FULL_LIVES;

	Rock rock(3);
	rocks.push_back(rock);
}

void Asteroids::playGame() {
	return;
}

void Asteroids::showMenu() {
	return;
}

void Asteroids::startLevel(int level) {
	return;
}

void Asteroids::update() {
	updateShip();
	updateRocks();
	updateBullets();
	return;
}

void Asteroids::draw() {
	window->clear();

	update();

	drawBullets();
	drawRocks();
	drawShip();

	window->display();
	return;
}

void Asteroids::checkEvent() {
	Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Q)
			|| Keyboard::isKeyPressed(Keyboard::Escape)) {
				window->close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				shoot();
			}
/*
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				if (rocks.size() > 0) splitRock(0);
			}
*/
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				rightPressed = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				leftPressed = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				upPressed = true;
			}
			break;
		case Event::KeyReleased:
			if (event.key.code == Keyboard::Right) {
				rightPressed = false;
			}
			if (event.key.code == Keyboard::Left) {
				leftPressed = false;
			}
			if (event.key.code == Keyboard::Up) {
				upPressed = false;
			}
			break;
		default:
			break;
		}
	}
	return;
}

void Asteroids::applyEvents() {
	if (leftPressed) ship.setRotate(-1);
	if (rightPressed) ship.setRotate(1);
	if (leftPressed == rightPressed) ship.setRotate(0); // if both are on or both off, don't turn
	if (upPressed) ship.startAccel();
	else ship.stopAccel();
}

void Asteroids::setFPS(int FPS) {
	window->setFramerateLimit(FPS);
	return;
}

bool Asteroids::isOpen() const {
	return window->isOpen();
}

void Asteroids::splitRock(int index) {
	vector<Rock> newRocks = rocks.at(index).split();             // get the rocks from the split
	rocks.insert(rocks.end(), newRocks.begin(), newRocks.end()); // add it to the rock vector
	rocks.erase(rocks.begin()+index);                            // erase the rock that split
	return;
}

void Asteroids::shoot() {
	Bullet newBullet;                          // make a new bullet
	newBullet.setRotation(ship.getRotation()); // orient it the same way as the ship
	newBullet.setXPos(ship.getXPos());         // move it to the ship's location
	newBullet.setYPos(ship.getYPos());
	bullets.push_back(newBullet);              // add it to the bullet vector
	return;
}

void Asteroids::drawBullets() {
	for (unsigned int i = 0; i < bullets.size(); i++) {
		bullets.at(i).draw(window);
	}
	return;
}

void Asteroids::drawRocks() {
	for (unsigned int i = 0; i < rocks.size(); i++) {
		rocks.at(i).draw(window);
	}
	return;
}

void Asteroids::drawShip() {
	ship.draw(window);
	return;
}

void Asteroids::drawLives() {
	return;
}

void Asteroids::updateRocks() {
	// move all the rocks
	for (unsigned int i = 0; i < rocks.size(); ++i) {
		rocks.at(i).update();
	}

	// check if the rock got hit by a bullet
	for (unsigned int i = 0; i < rocks.size(); ++i) {
		for (unsigned int j = 0; j < bullets.size(); ++j) {
			if (bullets.at(j).hit(rocks.at(i))) {
				splitRock(i);
				bullets.erase(bullets.begin()+j);
				break;
			}
		}
	}
	return;
}

// TODO finish the ship destroy method
void Asteroids::updateShip() {
	ship.update();
	for (unsigned int i = 0; i < rocks.size(); ++i) {
		if (rocks.at(i).checkShipCollision(ship)) {
			
		}
	}
	return;
}

void Asteroids::updateBullets() {
	for (unsigned int i = 0; i < bullets.size(); ++i) {
		bullets.at(i).update();
	}
	return;
}
