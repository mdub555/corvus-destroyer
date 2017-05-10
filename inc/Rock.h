/* Rock class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Ship.h"

class Rock {
private:
	static constexpr double PI = 3.14159265;

	int level;
	int radius;
	static const int NUM_POINTS = 16;

	double speed;
	double xVel;
	double yVel;

	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	void createShape();

public:
	ConvexShape rock;

	Rock(int level);

	double getX() const ;
	double getY() const ;
	double getXVel() const ;
	double getYVel() const ;

	void setPosition(double x, double y);
	void setVelocity(double x, double y);
	void setSpeed(double speed);

	void update();

	bool checkWallCollision();
	void wallCollision();

	bool checkShipCollision(const Ship& ship);
	void shipCollision(const Ship& ship);

	vector<Rock> split();

	void draw(RenderWindow* window) const ;

};
