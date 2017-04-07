/* Bullet class header for Asteroids clone game.
 *
 * Author: Mitchell Waibel
 *
 * Date: April 7, 2017
 */

#pragma once

#include "Rock.h"

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet {
private:
	static const double LENGTH = 10;

	double speed;
	double direction;

	static const int WINDOW_X = 1280;
	static const int WINDOW_Y = 1000;

	void createShape();

public:
	RectangleShape bullet;

	Bullet(double direction);

	void update();
	void move(int x, int y);
	void setPos(int x, int y);
	double getXPos() const ;
	double getYPos() const ;
	double getLength() const ;

	bool hit(const Rock& rock) const ;

	void draw(RenderWindow* window) const ;
};
