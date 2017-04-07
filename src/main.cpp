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

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;

#include "Rock.h"
#include "Ship.h"
#include "Bullet.h"

const int WINDOW_X = 1280;
const int WINDOW_Y = 1000;

// Declairing all variables that are best used gloRocky
Font myFont;

const int FULL_LIVES = 4;
int lives = FULL_LIVES;

int level = -1;
const int NUM_LEVELS = 5;

// rocks are in a vector because I was planning on making powerups that added rocks but didn't get
// to it
Ship ship;
vector<Rock> rocks;
vector<Bullet> Bullets;

bool playing = false;

RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), "Bullet Breaker!");

// function prototypes
void Menu();
void PlayGame();
bool CheckGameOver();
void GameOver();
void CheckEvent();

void DrawBullets();
void DrawLives();

void MoveRocks();
void MoveShip();
void CheckLoseLife();
void splitRock(int index);

void CheckFinishLevel();
void MakeLevel();

// loads the font and then plays the game while checking if the user wants to exit the game
int main() {
	srand(time(NULL));
	window.setFramerateLimit(30);

	Rock rock(3);
	rocks.push_back(rock);

	if (!myFont.loadFromFile("data/slkscr.ttf"))
		return 1;

	while (window.isOpen()) {
		window.clear();

		for (unsigned int i = 0; i < rocks.size(); i++) {
			rocks.at(i).draw(window);
		}

		PlayGame();
		CheckEvent();
		window.display();
	}
	return 0;
}

// outputs to the screen the title and play button
void Menu() {
	return;
}

// either plays the game or shows the main menu
void PlayGame() {
	return;
}

// checks if the user has no more lives left
bool CheckGameOver() {
	return false;
}

// function that outputs the menu for when the player loses
void GameOver() {
	return;
}

// checks for the user to exit the game of start the Rock moving off the Ship
void CheckEvent() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		} else if (event.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Q)
			|| Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();
			} else if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (rocks.size() > 0) {
					splitRock(0);
				}
			}
		}
	}
	return;
}

// draws each of the Bullets to the screen
void DrawBullets() {
	return;
}

void splitRock(int index) {
	vector<Rock> newRocks = rocks.at(0).split();
	rocks.insert(rocks.end(), newRocks.begin(), newRocks.end());
	rocks.erase(rocks.begin());
	return;
}

// makes a circle and draws it to the screen for each life the player has left
void DrawLives() {
	return;
}

// moves each of the rocks in the vector according to their x and y velocities
void MoveRocks() {
	return;
}

// moves the Ship to the x-position of the mouse and draws it to the screen
void MoveShip() {
	return;
}

// checks if the Rock hit the bottom side of the screen and if it has, decrements a life
void CheckLoseLife() {
	return;
}

// checks if there are no more Bullets on the screen
void CheckFinishLevel() {
	return;
}

// holds the information for each of the levels, and builds the vector that holds all the Bullets
// in the level
void MakeLevel() {
	return;
}
