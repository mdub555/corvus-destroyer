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
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Asteroids.h"

// loads the font and then plays the game while checking if the user wants to exit the game
int main() {
	srand(time(NULL));

	Asteroids game;
	game.setFPS(30);

	while (game.isOpen()) {
		game.draw();
		game.checkEvent();
	}
	return 0;
}

Asteroids::Asteroids() {
	window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), "Bullet Breaker!");
	level = -1;
	lives = FULL_LIVES;
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
	ship.update();
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
			} else if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (rocks.size() > 0) {
					splitRock(0);
				}
			} else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				ship.setRotate(1);
			} else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				ship.setRotate(-1);
			} else if (Keyboard::isKeyPressed(Keyboard::Up)) {
				ship.startAccel();
			}
			break;
		case Event::KeyReleased:
			if (event.key.code == Keyboard::Right
				|| event.key.code == Keyboard::Left) {
				ship.setRotate(0);
			} else if (event.key.code == Keyboard::Up) {
				ship.stopAccel();
			}
			break;
		default:
			break;
		}
	}
	return;
}

void Asteroids::setFPS(int FPS) {
	window->setFramerateLimit(FPS);
	return;
}

bool Asteroids::isOpen() const {
	return window->isOpen();
}

void Asteroids::splitRock(int index) {
	vector<Rock> newRocks = rocks.at(0).split();
	rocks.insert(rocks.end(), newRocks.begin(), newRocks.end());
	rocks.erase(rocks.begin());
	return;
}

void Asteroids::drawBullets() {
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
	return;
}

void Asteroids::updateShip() {
	return;
}
